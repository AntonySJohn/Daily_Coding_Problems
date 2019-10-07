/*
This problem was asked by Jane Street.
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the
first and last element of that pair. For example, car(cons(3, 4))
returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:
def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

Implement car and cdr.
*/

#include <cassert>
#include <functional>
#include <utility>

template <typename T1, typename T2>
using F = std::function<std::pair<T1, T2>(T1, T2)>;

template <typename T1, typename T2>
using Pair = std::function<std::pair<T1, T2>(F<T1, T2>)>;

template <typename T1, typename T2>
T1 car(Pair<T1, T2> pair) {
    F<T1, T2> f = std::make_pair<T1, T2>;
    return pair(f).first;
}

template <typename T1, typename T2>
T2 cdr(Pair<T1, T2> pair) {
    F<T1, T2> f = std::make_pair<T1, T2>;
    return pair(f).second;
}

template <typename T1, typename T2>
Pair<T1, T2> cons(T1 first, T2 second) {
    Pair<T1, T2> pair = [first, second](F<T1, T2> f) { return f(first, second); };
    return pair;
}

int main() {
    int a = 45;
    double b = 127.34;
    assert(a == car(cons(a, b)));
    assert(b == cdr(cons(a, b)));
    return 0;
}