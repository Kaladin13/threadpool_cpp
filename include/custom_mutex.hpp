#ifndef THREADPOOL_CPP_CUSTOM_MUTEX_HPP
#define THREADPOOL_CPP_CUSTOM_MUTEX_HPP

#include <atomic>
#include <thread>

class custom_mutex {

    std::atomic<bool> atomic_flag = false;

public:
    void lock() {
        while (atomic_flag.exchange(true)) {
            std::this_thread::yield();
        }
    }

    void unlock() {
        atomic_flag = false;
    }

};


#endif //THREADPOOL_CPP_CUSTOM_MUTEX_HPP
