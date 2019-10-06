/*
This problem was asked by Facebook.
A builder is looking to build a row of N houses that can be of 
K different colors. He has a goal of minimizing cost while 
ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column 
represents the cost to build the nth house with kth color, 
return the minimum cost which achieves this goal.
*/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <limits>

auto lowestCost(std::vector<std::vector<int>> costMatrix){
    std::size_t houses = costMatrix.size(), colors = costMatrix.at(0).size();
    int prevHouseMin = 0, prevHouseMinIndex = -1, prevHouseSecondMin = 0;

    for (std::size_t i = 0; i < houses; i++){
        int currHouseMin = std::numeric_limits<int>::max();
        int currHouseSecondMin = std::numeric_limits<int>::max();
        int currHouseMinIndex = 0;

        for (std::size_t j = 0; j < colors; j++){
            if (prevHouseMinIndex == j) costMatrix[i][j] += prevHouseSecondMin;
            else costMatrix[i][j] += prevHouseMin;
            if (currHouseMin > costMatrix[i][j]){
                currHouseSecondMin = currHouseMin;
                currHouseMin = costMatrix[i][j];
                currHouseMinIndex = j;
            }
            else if (currHouseSecondMin > costMatrix[i][j])
                currHouseSecondMin = costMatrix[i][j];
        }
        prevHouseMin = currHouseMin;
        prevHouseSecondMin = currHouseSecondMin;
        prevHouseMinIndex = currHouseMinIndex;
    }
    int retval = std::numeric_limits<int>::max();;
    for (auto& element : costMatrix.back()){
        retval = std::min(retval, element);
    }
    return retval;
}

int main(){
    //  rows        collumns
    int colors = 4, houses = 8, count(1);
    std::vector<std::vector<int>> example(colors, std::vector<int>(houses));
    std::cout << "Given the matrix: (each col is a house, each row a color)\n";
    for(auto& row : example){
        std::cout << "color " << count++ << ": [";
        for(auto& val : row) {
            val = rand()%20;
            std::cout << std::setw(2) << val << (&val == &row.back() ? "]" : ", ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "The minimal costs are: " << lowestCost(example);
    return 0;
}