/*
This problem was asked by Airbnb.
Given a list of integers, write a function that returns 
the largest sum of non-adjacent numbers. 
Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since 
we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, 
since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

#include <algorithm>
#include <limits>
#include <cassert>
#include <cstddef>
#include <vector>
#include <queue>

int largestSumAlt(const std::vector<int>& list){
    // pair<index, value>
    std::vector<std::pair<int,int>> largestThree;

    for (std::size_t i(0); i < list.size(); i++){
        if (largestThree.size() < 3){
            largestThree.push_back({i,list.at(i)});
            std::sort(largestThree.begin(), largestThree.end(),
                [](std::pair<int,int> f,std::pair<int,int> s){return f.second > s.second;});
        } else if (list.at(i) > largestThree.at(2).second){
            largestThree.push_back({i,list.at(i)});
            std::sort(largestThree.begin(), largestThree.end(),
                [](std::pair<int,int> f,std::pair<int,int> s){return f.second > s.second;});
            largestThree.pop_back();
        }
    }

    if (abs(largestThree.at(0).first - largestThree.at(1).first) == 1){
        if ((largestThree.at(0).second + largestThree.at(2).second) >
                (largestThree.at(1).second + largestThree.at(2).second))
            return largestThree.at(0).second + largestThree.at(2).second;
        else 
            return largestThree.at(1).second + largestThree.at(2).second;
    } else 
        return largestThree.at(0).second + largestThree.at(1).second;
}

int largestSum(const std::vector<int>& list){
    std::vector<int> sumBuilder = {0, 0};
    bool allNegatives = true;
    int greatestNegative = std::numeric_limits<int>::min();
    for (const auto& element : list){
        if (allNegatives && element < 0){
            if (element > greatestNegative) greatestNegative = element;
        } else {
            allNegatives = false;
        }
        sumBuilder = {sumBuilder.at(1), std::max(sumBuilder.at(1), sumBuilder.at(0) + element)};
    }
    return allNegatives? greatestNegative : sumBuilder.at(1);
}

int main(){
    // while testing the problems given example, i noticed that i 
    // accidently missunderstood the question and calculated the 
    // largest possible sum made of just two numbers
    assert(largestSumAlt({2, 4, 6, 2, 5}) == 11);
    assert(largestSumAlt({5, 1, 1, 5}) == 10);
    assert(largestSumAlt({-50, 5, 1, -40, -1}) == 4);

    // I decided to let the code as it is and just write another
    // function that takes multiple numbers to build the largest
    // possible sum
    assert(largestSum({2, 4, 6, 2, 5}) == 13);
    assert(largestSum({5, 1, 1, 5}) == 10);
    assert(largestSum({50, 1, 50, 500, 50}) == 550);
    assert(largestSum({-10, -10, -2, -10, -100}) == -2);
    return 0;
}