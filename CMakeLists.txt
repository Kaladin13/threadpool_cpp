cmake_minimum_required(VERSION 3.17)
project(threadpool_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(threadpool_cpp tests/main.cpp src/thread_pool.cpp include/thread_pool.hpp include/common.hpp include/custom_mutex.hpp include/task.hpp include/mutex_guard.hpp include/protected_queue.hpp)

target_link_libraries(threadpool_cpp pthread)
