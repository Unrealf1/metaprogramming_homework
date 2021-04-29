#pragma once

#include "Infantry.hpp"

class SavageInfantry : public Infantry {
public:
    std::string greeting() override {
        return Infantry::greeting() + " Now we are going to kill you.";
    }
};