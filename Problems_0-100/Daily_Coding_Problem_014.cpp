/*
This problem was asked by Google.
The area of a circle is defined as πr².
Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x² + y² = r².
*/

#include <cassert>
#include <random>

double getPi() {
    double testPoints(10'000'000), inside(0);
    std::random_device seed;
    std::mt19937 randomNumber(seed());
    std::uniform_real_distribution<> uni(-0.5, 0.5);

    auto circleTest = [](double x, double y) { return x * x + y * y <= 0.5 * 0.5; };

    for (int i = 0; i < testPoints; i++) {
        if (circleTest(uni(randomNumber), uni(randomNumber))) inside++;
    }

    return (4 * inside) / testPoints;
}

int main() { assert(fabs(getPi() - 3.141f) < 0.001f); }