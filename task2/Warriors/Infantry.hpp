#pragma once

#include <string>

class Infantry {
public:
    virtual std::string greeting() {
        return "Hello, good sir.";
    }
};