/*
This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 
1 or 2 steps at a time. Given N, write a function that returns the 
number of unique uniqueWays you can climb the staircase. The order of 
the steps matters.

For example, if N is 4, then there are 5 unique uniqueWays:
1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time, 
you could climb any number from a set of positive integers X?
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 
steps at a time.
*/

#include <iostream>
#include <cassert>
#include <vector>

int uniqueWays(int N, const std::vector<int>& X = {1, 2}){
    if (N == 1 ) return 1;

    auto calculated(new int[N+1]);
    calculated[0] = 1;
    
    for (int i = 1; i <= N; i++){
        int temp = 0;
        for (auto& stepSize : X){
            if (i - stepSize >= 0){
                temp += calculated[i - stepSize];
            }
        }
        calculated[i] = temp;
    }
    return calculated[N];
}

int main(){
    assert(uniqueWays(4) == 5);
    assert(uniqueWays(4, {1,2,3}) == 7);
    return 0;
}