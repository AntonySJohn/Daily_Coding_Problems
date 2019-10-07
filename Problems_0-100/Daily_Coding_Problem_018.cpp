/*
This problem was asked by Google.
Given an array of integers and a number k, where
1 <= k <= length of the array, compute the maximum
values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3,
we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)

Do this in O(n) time and O(k) space. You can modify the input array
in-place and you do not need to store the results.
You can simply print them out as you compute them.
*/

#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <vector>

auto maxOfSubarrays(const std::vector<int>& values, int k) {
    std::vector<int> returnVec;
    std::deque<int> dq(k);
    for (std::size_t i = 0; i < k; i++) {
        while (!dq.empty() && values.at(i) >= values.at(dq.back())) dq.pop_back();
        dq.push_back(i);
    }
    for (std::size_t i = k; i < values.size(); i++) {
        std::cout << values.at(dq.front()) << ' ';
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && values.at(i) >= values.at(dq.back())) dq.pop_back();
        dq.push_back(i);
    }
    std::cout << values.at(dq.front());
}

int main() {
    std::vector<int> example{10, 5, 2, 7, 8, 7};
    int k = 3;
    maxOfSubarrays(example, k);
    return 0;
}