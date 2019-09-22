/*
This problem was asked by Apple.
Implement a job scheduler which takes in a function f 
and an integer n, and calls f after n milliseconds.
*/

#include <functional>
#include <iostream>
#include <thread>
#include <chrono>

auto printElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> startTime) -> void{
    auto endTime = std::chrono::high_resolution_clock::now();
    auto tElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "Time elapsed since scheduler-call: " << tElapsed.count() << std::endl;
}

template <typename f>
auto schedule(int sleeptime, f callback) -> void {

    std::thread t1([=](int sleeptime, f callback){
        std::chrono::milliseconds sleepDuration(sleeptime);
        auto startTime = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(sleepDuration);
        callback(startTime);
    });
    t1.detach();
}

int main(){
    schedule(3000, printElapsedTime);
    std::chrono::milliseconds sleepDuration(5000);
    std::this_thread::sleep_for(sleepDuration);
    return 0;
}