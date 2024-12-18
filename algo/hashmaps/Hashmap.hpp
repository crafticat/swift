#pragma once
#include "string"

class Hashmap {

public:
    Hashmap() = default;
    virtual void insert(int x, int y) = 0;
    virtual void resize(int n) = 0;
    virtual int get(int x) = 0;
    virtual std::string getName() = 0;
};