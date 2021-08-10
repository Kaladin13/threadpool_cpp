//
// Created by kaladin on 10.08.2021.
//

#ifndef THREADPOOL_CPP_TH_POOL_H
#define THREADPOOL_CPP_TH_POOL_H

#include "common.h"

struct task;

class th_pool {
private:
    std::vector<std::thread> threads;
    std::deque<task> tasks;
    std::mutex main_mutex;
public:

};


#endif //THREADPOOL_CPP_TH_POOL_H
