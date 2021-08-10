#ifndef THREADPOOL_CPP_THREAD_POOL_HPP
#define THREADPOOL_CPP_THREAD_POOL_HPP

#include "common.h"
#include "task.hpp"

class thread_pool {
private:
    std::vector<std::thread> threads;
    std::deque<task> task_queue;

    thread_pool(const thread_pool &) = delete;
    thread_pool & operator=(thread_pool &) = delete;

    thread_pool(thread_pool &&) = delete;
    thread_pool && operator=(thread_pool &&) = delete;


public:

    explicit thread_pool();

    virtual ~thread_pool() = default;
};


#endif //THREADPOOL_CPP_THREAD_POOL_HPP
