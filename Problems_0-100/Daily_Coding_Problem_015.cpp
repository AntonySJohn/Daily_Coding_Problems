/*
This problem was asked by Facebook.
Given a stream of elements too large to store in memory, 
pick a random element from the stream with uniform probability.
*/

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int reservoirSampling(const std::vector<int>& stream){
    int index(1), currentSample = 0;
    std::for_each(stream.begin(), stream.end(),
                  [&index, &currentSample](const auto &element) {
                      if (rand() % index++ == 0)
                          currentSample = element;
                  });
    return currentSample;
}

int main(){
    std::vector<int> exanmple{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    for (int i = 0; i < 5; i++){
        std::cout << reservoirSampling(exanmple) << std::endl;
    }
    return 0;
}