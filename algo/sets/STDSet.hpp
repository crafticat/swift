#pragma once

#include "Set.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#include "bits/stdc++.h"

using namespace std;

class STDSet : public Set {
    set<int> s;

    void insert(int x) {
        s.insert(x);
    }
    int lb(int x) {
        auto it = s.lower_bound(x);
        if (s.end() == it) return 1e9;
        return *it;
    }

    string getName() override {
        return "STDSet";
    }
};