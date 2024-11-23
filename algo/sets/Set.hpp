#pragma once

#include "bits/stdc++.h"

using namespace std;

class Set {
public:
    virtual void insert(int x) = 0;
    virtual int lb(int x) = 0;
    virtual string getName() = 0;
};