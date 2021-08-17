//
// Created by kaladin on 17.08.2021.
//

#ifndef THREADPOOL_CPP_PROTECTED_QUEUE_HPP
#define THREADPOOL_CPP_PROTECTED_QUEUE_HPP

#include <deque>
#include "custom_mutex.hpp"
#include "mutex_guard.hpp"

template<typename T>
class protected_queue { //default queue protected for multithreading use
private:
    std::deque<T> deque;
    custom_mutex mutex;

    protected_queue(const protected_queue &) = delete;

    protected_queue &operator=(protected_queue &) = delete;

    protected_queue(protected_queue &&) = delete;

    protected_queue &&operator=(protected_queue &&) = delete;

public:

    protected_queue() = default;

    void push_back(T item) {
        mutex_guard guard(mutex);
        deque.push_back(item);
    }

    bool empty() {
        mutex_guard guard(mutex);
        return deque.empty();
    }

    void pop_back() {
        mutex_guard guard(mutex);
        deque.pop_back();
    }

    void pop_front() {
        mutex_guard guard(mutex);
        deque.pop_front();
    }

    auto front() {
        mutex_guard guard(mutex);
        return deque.front();
    }

    auto back() {
        mutex_guard guard(mutex);
        return deque.back();
    }

    void resize(int item) {
        mutex_guard guard(mutex);
        deque.resize(item);
    }

    T &operator[](int i) {
        mutex_guard guard(mutex);
        return deque[i];
    }

    auto size() {
        mutex_guard guard(mutex);
        return deque.size();
    }

};


#endif //THREADPOOL_CPP_PROTECTED_QUEUE_HPP
