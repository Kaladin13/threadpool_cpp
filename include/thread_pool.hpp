#ifndef THREADPOOL_CPP_THREAD_POOL_HPP
#define THREADPOOL_CPP_THREAD_POOL_HPP

#include "common.h"
#include "task.hpp"

class thread_pool {
private:
    enum{
        default_thread_num = 4
    };

    const size_t MAX_NUMBER_OF_THREADS = std::thread::hardware_concurrency();
    const size_t current_number_of_threads;

    std::vector<std::thread> threads;
    std::deque<task> task_queue;
    std::vector<size_t> empty_threads; // to contain indexes of threads that are ready to run

    thread_pool(const thread_pool &) = delete;
    thread_pool & operator=(thread_pool &) = delete;

    thread_pool(thread_pool &&) = delete;
    thread_pool && operator=(thread_pool &&) = delete;


public:

    explicit thread_pool(); //default 4 threads

    explicit thread_pool(int number_of_threads); //custom number of threads

    virtual ~thread_pool() = default;
};


#endif //THREADPOOL_CPP_THREAD_POOL_HPP
