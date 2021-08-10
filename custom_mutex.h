//
// Created by kaladin on 10.08.2021.
//

#ifndef THREADPOOL_CPP_CUSTOM_MUTEX_H
#define THREADPOOL_CPP_CUSTOM_MUTEX_H

#include <atomic>
#include <iostream>

class custom_mutex {
//class of mutex implemented with atomic var, faster than std::mutex
private:
    std::atomic<bool> atomic_bool = false;
public:
    void lock() {
        while (atomic_bool) {} //waiting for unlock
        atomic_bool = true;
    }

    void unlock() {
        atomic_bool = false;
    }
};


#endif //THREADPOOL_CPP_CUSTOM_MUTEX_H
