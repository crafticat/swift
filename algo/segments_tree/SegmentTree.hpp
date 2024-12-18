#pragma once

#include <vector>

template<typename T>
class SegmentTree {
    size_t size;

    SegmentTree(){
    }

    void generate(const std::vector<T> &v) {
        create(v);
        size = v.size();
    }

    virtual void create(const std::vector<T> &v);
    virtual T query(int l, int r);
    virtual void update(int x, T val);
};