#pragma once

#include "SegmentTree.hpp"
#include "../../utils/math.hpp"

template<typename T>
class SegmentTreeIter : public SegmentTree<T> {
    std::vector<T> st;
    size_t stSize;

    void create(const std::vector<T> &v) override {
        stSize = next2pow(v.size());
        st.assign(2 * stSize);

        for(int i = 0; i < v.size(); i++)
            st[stSize + i] = v[i];
        for(int i = stSize - 1; i > 0; i--)
            st[i] = st[2 * i] + st[2 * i + 1];
    }

    T query(int l, int r) override {
        T res = T();
        for(l += stSize, r += stSize; l < r; l >>= 1, r >>= 1){
            if(l % 2) res += st[l++];
            if(r % 2) res += st[--r];
        }
    }

    T update(int x, T val) override{
        for(st[x += stSize] = val; x > 1; x >>= 1)
            st[x >> 1] = st[x] + st[x ^ 1];
    }
};