#ifndef THREADPOOL_CPP_MUTEX_GUARD_HPP
#define THREADPOOL_CPP_MUTEX_GUARD_HPP


template<typename Mutex>
class mutex_guard {

    Mutex & mutex_ref;

    mutex_guard(const mutex_guard &) = delete;

    mutex_guard & operator=(mutex_guard &) = delete;

    mutex_guard(mutex_guard &&) = delete;

    mutex_guard && operator=(mutex_guard &&) = delete;

public:
    explicit mutex_guard(Mutex & ref);

    virtual ~mutex_guard();

};



#endif //THREADPOOL_CPP_MUTEX_GUARD_HPP
