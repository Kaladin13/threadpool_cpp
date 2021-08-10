//
// Created by kaladin on 10.08.2021.
//

#include "th_pool.h"
struct task{
    std::function<void(int)> function;
    int argument;
};

class task_handler{
    std::thread th;
    std::mutex mutex;
    task m_task;
    bool is_working;
    bool add_task(task& t){
        std::unique_lock lock(mutex);
        if (is_working) return false;
        m_task = std::move(t);
        is_working = true;
        return true;
    }
    void run(){
        while (true){
           // th(m_task.function, m_task.argument);
        }
    }
};

