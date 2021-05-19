#include <iostream>

#include "LifetimeTracker.hpp"
#include "Longevity.hpp"

struct A {
    A(int a): _a(a) {
        std::cout << '(' << _a << ") A is created!\n";
    }

    ~A() {
        std::cout << '(' << _a << ") A is destroyed\n";
    }
    const int _a;
};



int main() {
    auto first = new A(1);
    auto second = new A(2);
    auto third = new A(3);
    SetLongevity(first, 3);
    SetLongevity(second, 2);
    SetLongevity(third, 1);
}