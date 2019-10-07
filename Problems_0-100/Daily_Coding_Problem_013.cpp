/*
This problem was asked by Amazon.
Given an integer k and a string s, find the length of the
longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest
substring with k distinct characters is "bcb".
*/

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

auto longestSubstring(int distinct, const std::string& str) {
    std::vector<std::pair<char, int>> distChars;
    int maxSubsting = 0;

    // find longest substring for every char in the string
    // as begin point of the search
    std::for_each(str.begin(), str.end(), [&maxSubsting, &distChars, &distinct](const auto& ch) {
        distChars.push_back({ch, 1});
        auto itr = &ch;

        // loop to the end of the string from the current char onwards
        while (*(itr++)) {
            // when the char is not in the set of already seen chars
            //(if the char is in the seen ones, increment the chars counter)
            if (std::find_if(distChars.begin(), distChars.end(), [&itr](std::pair<char, int>& p) {
                    if (p.first == *itr) {
                        p.second++;
                        return true;
                    } else
                        return false;
                }) == distChars.end()) {
                // maximum distinct integers found
                if (distChars.size() == distinct) {
                    int temp = 0;
                    for (const auto& p : distChars) temp += p.second;
                    maxSubsting = std::max(maxSubsting, temp);
                    break;

                    // we have distinct char left to add
                } else {
                    distChars.push_back({*itr, 1});
                }
            }
        }
        distChars.clear();
    });
    return maxSubsting;
}

int main() {
    assert(longestSubstring(2, "abcba") == 3);
    assert(longestSubstring(8, "") == 0);
    assert(longestSubstring(3, "aaaabcdeffffff") == 8);
    return 0;
}