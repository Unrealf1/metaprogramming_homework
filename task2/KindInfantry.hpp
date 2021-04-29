#pragma once

#include "Infantry.hpp"

class KindInfantry : public Infantry {
public:
    std::string greeting() override {
        return Infantry::greeting() + " We will make sure, that you are safe.";
    }
};
