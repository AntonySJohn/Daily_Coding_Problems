/*
This problem was asked by Stripe.
Given an array of integers, find the first missing positive integer
in linear time and constant space. In other words, find the lowest
positive integer that does not exist in the array. The array can
contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. 
The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

#include <iostream>
#include <cstddef>
#include <cassert>
#include <vector>

auto findLowestPositiveMissingInt(const std::vector<int>&) -> int;

int main(){
    assert(findLowestPositiveMissingInt({3, 4, -1, 1}) == 2);
    assert(findLowestPositiveMissingInt({1, 2, 0}) == 3);
    assert(findLowestPositiveMissingInt({1, 2, 12, 39, 4, 8, 3, 7}) == 5);
    return 0;
}

int findLowestPositiveMissingInt(const std::vector<int>& numbers){

    // because the first positive int is wanted, remove all ints 
    // that are less then zero and add them to a temp array
    std::size_t max(0);
    std::vector<int> positiveNumbers;
    for (const auto& num : numbers){
        if (num >=  0) positiveNumbers.push_back(num);
    }

    // now we go through the array, and if a number is smaller
    // then the arrays size, we take the index of the numbers value
    // and change the entry at this index to become negative
    // i skip every 0 because its occurrence is optional
    for (std::size_t i = 0; i < positiveNumbers.size(); i++){
        auto currVal = positiveNumbers.at(i);
        if (currVal == 0) continue;
        if (abs(currVal) <= static_cast<int>(positiveNumbers.size())){
            positiveNumbers.at(abs(currVal) - 1) = -abs(positiveNumbers.at(abs(currVal) - 1));
        }
    }

    // now we just search for the first positive number, the
    // index of this number is the first positive missing int
    for (std::size_t i = 0; i < positiveNumbers.size(); i++){
        if (positiveNumbers.at(i) > 0){
            return i + 1;
        }
    }

    // case the given set is complete
    return positiveNumbers.size();
}