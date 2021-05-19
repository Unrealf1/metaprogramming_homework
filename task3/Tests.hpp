#pragma once

#include <vector>
#include <random>

#include "TestStruct.hpp"
#include "LifetimeTracker.hpp"
#include "Longevity.hpp"

static void create_with_longevity(int longevity, order_t& order) {
    SetLongevity(new A(longevity, order), longevity);
}

void simple_test() {
    order_t reference_order = {1, 2, 3, 4, 5};
    order_t real_order;

    create_with_longevity(1, real_order);
    create_with_longevity(3, real_order);
    create_with_longevity(5, real_order);
    create_with_longevity(4, real_order);
    create_with_longevity(2, real_order);
}

void random_test() {
    order_t real_order;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);

    for (int n = 0; n < 200; ++n) {
        create_with_longevity(distrib(gen), real_order);
    }
}