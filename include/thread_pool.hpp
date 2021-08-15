#ifndef THREADPOOL_CPP_THREAD_POOL_HPP
#define THREADPOOL_CPP_THREAD_POOL_HPP

#include "common.hpp"
#include "task.hpp"
#include "custom_mutex.hpp"
#include "mutex_guard.hpp"

class thread_pool {

    static constexpr int default_thread_num = 4;
    const size_t MAX_NUMBER_OF_THREADS = std::thread::hardware_concurrency() - 1;
    const size_t current_number_of_threads;

    std::vector<std::thread> threads;
    std::deque<std::function<void(void)>> task_queue;//contain functions with different signatures wrapped to void(void)
    std::vector<size_t> empty_threads; //contain indexes of threads that are ready to run

    custom_mutex main_mutex;

    thread_pool(const thread_pool &) = delete;

    thread_pool &operator=(thread_pool &) = delete;

    thread_pool(thread_pool &&) = delete;

    thread_pool &&operator=(thread_pool &&) = delete;

    void reset_thread(int index_of_thread);

    void schedule();

public:

    explicit thread_pool(int number_of_threads = default_thread_num); //default is 4 threads

    virtual ~thread_pool() = default;

    template<typename Function, typename ... Args>
    void add_task(Function &&  function, Args && ... args);

};


#endif //THREADPOOL_CPP_THREAD_POOL_HPP
