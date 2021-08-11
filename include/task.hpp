#ifndef THREADPOOL_CPP_TASK_HPP
#define THREADPOOL_CPP_TASK_HPP


class task {

};

template<typename Func, typename ... Args,
        std::enable_if_t<std::is_invocable_v<Func, Args ...>, bool> = true>
constexpr decltype(auto) create_func(Func func, Args ... args) {
    return func(std::forward<Args>(args)...);
}

template<typename Func>
constexpr decltype(auto) create_func(Func func){
    return func();
}

#endif //THREADPOOL_CPP_TASK_HPP
