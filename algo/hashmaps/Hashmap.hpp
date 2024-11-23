#pragma once
#include "bits/stdc++.h"

using namespace std;

class Hashmap {

public:
    virtual void insert(int x, int y) = 0;
    virtual void resize(int n) = 0;
    virtual int get(int x) = 0;
    virtual string getName() = 0;
};