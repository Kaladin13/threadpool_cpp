#ifndef THREADPOOL_CPP_TASK_HPP
#define THREADPOOL_CPP_TASK_HPP

#include "common.h"

template<typename Function, typename ... Args>
class task {

private:

    std::function<void(void)> function; //void(void) signature because args are already bound

public:

    task(std::function<std::invoke_result_t<Function, Args ...>(Args ...)> f, Args ... args) {
        function = create_func(f, args ...);//create function here and check if signature is invokable
    }

    auto get_task() {
        return function; //return function and not function() because we don't need it to run now
    }

};

template<typename Func, typename ... Args,
        typename = std::enable_if_t<std::is_invocable_v<Func, Args ...>>>
constexpr auto create_func(Func func, Args ... args) {
    return [=]() { return func((args)...); };
}

#endif //THREADPOOL_CPP_TASK_HPP
