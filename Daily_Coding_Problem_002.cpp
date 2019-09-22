/*
This problem was asked by Uber.
Given an array of integers, return a new array such that each element at index 
i of the new array is the product of all the numbers in the original array 
except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would 
be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output 
would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <iostream>
#include <vector>
#include <cstddef>

//O(n) = n^2 -> already no division used
auto multiply(const std::vector<int>& ) -> std::vector<int>;
auto printVectorAsArray(const std::vector<int>&) -> void;

int main(){
    std::vector<int> example = {1, 2, 3, 4, 5};
    std::vector<int> example1 = {3, 2, 1};

    auto modifiedExample(multiply(example));
    auto modifiedExample1(multiply(example1));

    std::cout << "base array : ";
    printVectorAsArray(example);
    std::cout << "modified   : ";
    printVectorAsArray(modifiedExample);

    std::cout << "----------------------------------" << std::endl;

    std::cout << "base array : ";
    printVectorAsArray(example1);
    std::cout << "modified   : ";
    printVectorAsArray(modifiedExample1);

    return 0;
}

std::vector<int> multiply(const std::vector<int>& oldArray){
    std::vector<int> temp;
    int val(0);
    for (std::size_t i = 0; i < oldArray.size(); i++){
        for (std::size_t j = 0; j < oldArray.size(); j++){
            if (i == j) continue;
            if (j == 0) {
                val  = oldArray.at(0);
                continue;
            }
            if (i == 0 && j == 1){
                val = oldArray.at(1);
                continue;
            }
            val *= oldArray.at(j);
        }
        temp.push_back(val);
    }
    return temp;
}

void printVectorAsArray(const std::vector<int>& vec){
    for (const auto& entry : vec){
        if (&entry == &vec.back()) {
            std::cout << entry << "]" << std::endl;
            break;
        }
        if (&entry == &vec.front()) {
            std::cout << "[";
        }
        std::cout << entry << ", ";
    }
}