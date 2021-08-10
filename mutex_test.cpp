#include <iostream>
#include "common.h"
#include "custom_mutex.h"

void f(custom_mutex &mutex) {
    mutex.lock();
    for (int i = 0; i < 15; i++) {
        std::cout << std::this_thread::get_id() << " " << i << std::endl;
    }
    mutex.unlock();
}

int main() {
    custom_mutex custom_mutex;
    std::thread th1([&]() {
        f(custom_mutex);
    });
    std::thread th2([&]() {
        f(custom_mutex);
    });
    th1.join();
    th2.join();
    return 0;
}
