#pragma once

#include "Cavalry.hpp"

class KindCavalry : public Cavalry {
public:
    std::string greeting() override {
        return Cavalry::greeting() + " We will make sure, that you are safe.";
    }
};
