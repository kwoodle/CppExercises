//
// Created by kwoodle on 1/31/19.
//
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

using namespace std::chrono;
using std::mutex;

mutex cout_mutex;

void hello() {
    for (int i = 0; i < 20; ++i) {
        cout_mutex.lock();
        std::cout << "Hello ";
        cout_mutex.unlock();
        std::this_thread::sleep_for(seconds{1});
    }
}

void world() {
    for (int i = 0; i < 20; ++i) {
        cout_mutex.lock();
        std::cout << "world.\n";
        cout_mutex.unlock();
        std::this_thread::sleep_for(seconds{1});
    }
}


// X.6 [2]
// (∗1.5) Write a program with two tread s: one that writes hello ev ery second and one that
// writes world! ev ery second.
//
int main() {
    std::thread t1{hello};
    std::thread t2{world};

    t1.join();
    t2.join();

    return 0;
}
