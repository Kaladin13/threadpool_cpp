#ifndef THREADPOOL_CPP_THREAD_POOL_HPP
#define THREADPOOL_CPP_THREAD_POOL_HPP

#include "common.hpp"
#include "task.hpp"
#include "protected_queue.hpp"

class thread_pool {

    static constexpr int default_thread_num = 4;
    const size_t MAX_NUMBER_OF_THREADS = std::thread::hardware_concurrency() - 1;
    const size_t current_number_of_threads;

    protected_queue<std::thread> threads;
    protected_queue<std::function<void(void)>> task_queue;//contain functions with different signatures wrapped to void(void)
    protected_queue<size_t> empty_threads; //contain indexes of threads that are ready to run

    thread_pool(const thread_pool &) = delete;

    thread_pool &operator=(thread_pool &) = delete;

    thread_pool(thread_pool &&) = delete;

    thread_pool &&operator=(thread_pool &&) = delete;

    void schedule();

public:

    explicit thread_pool(int number_of_threads = default_thread_num); //default is 4 threads

    virtual ~thread_pool(){
        for (int i = 0;i<current_number_of_threads;i++){
            if (threads[i].joinable())
                threads[i].join();
        }
    }

    //creates and adds a new task, signature is always void(void) after
    template<typename Function, typename ... Args>
    void add_task(Function &&  function, Args && ... args){
        task_queue.push_back(create_func(std::forward<Function>(function), std::forward<Args>(args)...));
        schedule();
    }

};


#endif //THREADPOOL_CPP_THREAD_POOL_HPP
