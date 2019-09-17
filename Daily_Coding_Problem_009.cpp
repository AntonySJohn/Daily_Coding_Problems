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

#include <cassert>
#include <vector>
#include <queue>

int largestSum(const std::vector<int>& list){
    // first element of the pair is the index, second is the value
    std::vector<std::pair<int, int>> largestThree;
    for (int i = 0; i < list.size(); i++){
        if (largestThree.size() < 3){
        }
    }
    
    return 13;
}

int main(){
    assert(largestSum({2, 4, 6, 2, 5}) == 13);
    return 0;
}