/*
This Problem wasy recently asked by Google.
Given a list of numbers and a number k, return wheather any two
numberrs from the list add up to k.

For example, given [10, 15, 3, 7] and k = 17, return true,
since 10 + 7 = 17.

Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <vector>

// O(n) = n^2
auto isSum(const std::vector<int>&, const int&) -> bool;
auto operator<<(std::ostream&, const std::vector<int>&) -> std::ostream&;

int main() {
    const std::vector<int> example = {10, 15, 3, 7};
    int targetSum(17);

    std::cout << targetSum << " is sum of two entrys in the list: " << example << " -> ";

    std::cout.setf(std::ios_base::boolalpha);
    std::cout << isSum(example, targetSum) << std::endl;
    return 0;
}

bool isSum(const std::vector<int>& list, const int& targetSum) {
    // vector to store complements of list-entrys
    std::vector<int> complements(list.size());

    for (auto& listEntry : list) {
        for (auto& complementEntry : complements) {
            if (listEntry == complementEntry) {
                return true;
            }
        }
        complements.push_back(targetSum - listEntry);
    }

    return false;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    for (const auto& entry : vec) {
        if (&entry == &vec.back()) {
            os << entry << "]";
            break;
        }
        if (&entry == &vec.front()) {
            os << "[";
        }
        os << entry << ", ";
    }
}