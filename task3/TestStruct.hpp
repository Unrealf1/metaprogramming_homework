#pragma once

#include <iostream>
#include <vector>

using order_t = std::vector<int>;

class WrongOrderException : public std::exception {
public:
    const char* what() const noexcept {
        return "The order is wrong!";
    }
};

struct A {    
    A(int a, order_t& destroy_order): _a(a), _destroy_order(destroy_order) {
        std::cout << '(' << _a << ")\tA is created!\n";
    }

    ~A() {
        if (_a < last_destroyed) {
            throw WrongOrderException();
        }
        _destroy_order.push_back(_a);
        std::cout << '(' << _a << ")\tA is destroyed\n";
    }
    const int _a;
private:
    static int last_destroyed;
    order_t& _destroy_order;
};

int A::last_destroyed = -1;
