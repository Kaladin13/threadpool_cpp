cmake_minimum_required(VERSION 3.17)
project(threadpool_cpp)

set(CMAKE_CXX_STANDARD 17)

add_library(threadpool_cpp src/thread_pool.cpp include/thread_pool.hpp include/common.h include/custom_mutex.hpp include/task.hpp)

target_link_libraries(threadpool_cpp pthread)
