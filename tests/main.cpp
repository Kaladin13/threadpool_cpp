#include <iostream>
#include "../include/thread_pool.hpp"
void f(int a){
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << a << std::endl;
}

int main(){
    thread_pool threadPool(7);
    for (int i = 0;i<10000;i++){
        threadPool.add_task(f,i);
    }
}