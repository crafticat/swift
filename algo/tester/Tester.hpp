#pragma once

#include "TestResults.hpp"

class Tester {

public:
    int iter;
    virtual TestResults run(int siz) = 0;

protected:
    Tester() = default;
};