/*
This problem was asked by Facebook.
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
count the number of ways it can be decoded.

For example, the message '111' would give 3, since it
could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable.
For example, '001' is not allowed.
*/

#include <cassert>
#include <string>

int decode(const std::string& message) {
    if (message.size() == 1) return 1;
    if (message.size() == 2) return (std::stoi(message) > 26 ? 1 : 2);
    if (std::stoi(message.substr(0, 2)) > 26) return decode(message.substr(1));
    return decode(message.substr(1)) + decode(message.substr(2));
}

int main() {
    assert(decode("111") == 3);
    assert(decode("81") == 1);
    assert(decode("6") == 1);
    assert(decode("21") == 2);
    return 0;
}
