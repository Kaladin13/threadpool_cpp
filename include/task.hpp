#ifndef THREADPOOL_CPP_TASK_HPP
#define THREADPOOL_CPP_TASK_HPP

#include "common.h"

template<typename Func, typename ... Args,
        typename = std::enable_if_t<std::is_invocable_v<Func, Args ...>>>
constexpr auto create_func(Func func, Args ... args) {                  //cast to function<void(void)>
    return std::function<void(void)>([=]() { return func((args)...); });//to have single signature in all tasks
}

#endif //THREADPOOL_CPP_TASK_HPP
