#ifndef THREADPOOL_CPP_TASK_HPP
#define THREADPOOL_CPP_TASK_HPP

#include "common.h"

template<typename Function, typename ... Args>
class task {

private:

    std::function<std::invoke_result_t<Function, Args ...> ()> function;

public:

    task(std::function<std::invoke_result_t<Function, Args ...> (Args ...)> f, Args ... args){
        function = create_func(f,args ...);//create function here and check if signature is invokable
    }

    auto run(){
        return function();
    }

};

template<typename Func, typename ... Args,
        std::enable_if_t<std::is_invocable_v<Func, Args ...>, bool> = true>
constexpr decltype(auto) create_func(Func func, Args ... args) {
    std::function<Func(Args ...)> function_to_return = std::bind(func, args ...);
    return function_to_return;
}

//template<typename Func>
//constexpr decltype(auto) create_func(Func func){
//    return func();
//}

#endif //THREADPOOL_CPP_TASK_HPP
