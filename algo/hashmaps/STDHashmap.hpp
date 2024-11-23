#pragma once

#include "Hashmap.hpp"
#include "bits/stdc++.h"

using namespace std;

class STDHashmap : public Hashmap {
    unordered_map<int, int> map;

    void insert(int x, int y) override {
        map[x] = y;
    }
    int get(int x) override {
        return map[x];
    }
    void resize(int n) {
        map.reserve(n);
    }

    string getName() override {
        return "STD unordered map";
    }
};