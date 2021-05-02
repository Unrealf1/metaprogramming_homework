#pragma once

#include <string>

class Cavalry {
public:
    virtual std::string greeting() {
        return "Hello, good sir, we're riding horses.";
    }
};