#include "../include/thread_pool.hpp"

thread_pool::thread_pool(int number_of_threads) : current_number_of_threads(
        (number_of_threads <= MAX_NUMBER_OF_THREADS || number_of_threads > 0) ?
        number_of_threads - 1 : MAX_NUMBER_OF_THREADS) {
    //here handling incorrect number of threads

    threads.resize(current_number_of_threads);

    for (size_t i = 0; i < current_number_of_threads; ++i) {
        empty_threads.push_back(i); //at start all threads are empty
    }
}

//assign tasks to empty threads, if all threads are busy, then wait
void thread_pool::schedule() {

    while (!task_queue.empty()) {

        if (empty_threads.empty()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); //TODO find optimal constant
            continue;
        }

        auto current_task = task_queue.front();
        task_queue.pop_front();

        //capturing thread_num early to avoid memory race errors
        auto number_of_thread = empty_threads.size() - 1;
        empty_threads.pop_back();


        if (threads[number_of_thread].joinable()) {
            threads[number_of_thread].join();
        }
        threads[number_of_thread] = std::thread([this](auto num, auto task) {
            task();
            empty_threads.push_back(num);
        }, number_of_thread, current_task);

    }

}
