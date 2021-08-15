#include "../include/mutex_guard.hpp"


template<typename Mutex>
mutex_guard<Mutex>::mutex_guard(Mutex &ref) : mutex_ref(ref) {
    mutex_ref.lock();
}

template<typename Mutex>
mutex_guard<Mutex>::~mutex_guard<Mutex>() {
    mutex_ref.unlock();
}