#pragma once

#include "Cavalry.hpp"

class SavageCavalry : public Cavalry {
public:
    std::string greeting() override {
        return Cavalry::greeting() + " Now we are going to kill you.";
    }
};
