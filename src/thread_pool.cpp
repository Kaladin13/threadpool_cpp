#include "../include/thread_pool.hpp"


thread_pool::thread_pool(int number_of_threads) : current_number_of_threads(number_of_threads - 1) {

    //what to do here if number_of_threads is incorrect value?
    if (!(number_of_threads <= MAX_NUMBER_OF_THREADS || number_of_threads > 0)) {
        //handle_error
        //TODO
    }

    threads.resize(current_number_of_threads);

    for (int i = 0; i < current_number_of_threads; i++)
        empty_threads.push_back(i); //at start all threads are empty

}

//creates and adds a new task, signature is always void(void) after
template<typename Function, typename ... Args>
void thread_pool::add_task(Function function, Args ... args) {
    task_queue.emplace_back(create_func(function, args ...));
    schedule();
}

//assign tasks to empty threads, and then wait for them to run
void thread_pool::schedule() {
    main_mutex.lock();

    while (!task_queue.empty()) {
        if (empty_threads.empty()){
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); //TODO
            continue;
        }

        if (threads[empty_threads.back()].joinable())
            threads[empty_threads.back()].join();

        auto current_task = task_queue.front();
        task_queue.pop_front();

        auto number_of_thread = empty_threads.size()-1;
        threads[empty_threads.back()] = std::thread([&]() {
            current_task();//doing the task here
            reset_thread(number_of_thread);
        });


        empty_threads.pop_back();
    }

    main_mutex.unlock();
}

//after the thread has finished the task, he is added back to empty_threads
void thread_pool::reset_thread(int index_of_thread) {
    main_mutex.lock();
    empty_threads.push_back(index_of_thread);
    main_mutex.unlock();
}