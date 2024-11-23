#pragma once

#include "Hashmap.hpp"
#include "bits/stdc++.h"

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

class GPHashmap : public Hashmap {
    gp_hash_table<int, int, hash<int>, equal_to<int>, direct_mask_range_hashing<>,
            linear_probe_fn<>,
            hash_standard_resize_policy<hash_exponential_size_policy<>,
                    hash_load_check_resize_trigger<>, true>> map;

    void insert(int x, int y) override {
        map[x] = y;
    }
    int get(int x) override {
        return map[x];
    }
    void resize(int n) override {
        map.resize(n);
    }
    string getName() override {
        return "gp_hash_table";
    }
};