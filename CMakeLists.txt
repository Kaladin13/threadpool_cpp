cmake_minimum_required(VERSION 3.20)
project(threadpool_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(threadpool_cpp mutex_test.cpp th_pool.cpp th_pool.h common.h custom_mutex.h tasker.h)

target_link_libraries(threadpool_cpp pthread)
