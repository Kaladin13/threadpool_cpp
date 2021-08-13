#include "../include/thread_pool.hpp"


thread_pool::thread_pool(int number_of_threads) : current_number_of_threads(number_of_threads) {

    //what to do here if number_of_threads is incorrect value?
    if (!(number_of_threads <= MAX_NUMBER_OF_THREADS || number_of_threads > 0)) {
        //handle_error
    }

    threads.resize(current_number_of_threads);

    for (int i = 0; i < current_number_of_threads; i++)
        empty_threads.push_back(i); //at start all threads are empty

}

//adds new task as std::any, signature is always void(void) after
template <typename Function, typename ... Args>
void thread_pool::add_task(Function function, Args ... args) {
    task<Function,Args ...> m_task(function,args ...);
    task_queue.template emplace_back(m_task.get_task());
}

//first use any_cast to access function at front of task queue,
//then runs it
void thread_pool::run() {
    std::any_cast<std::function<void(void)>>(task_queue.front())();
}