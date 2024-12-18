#pragma once

#include "SegmentTree.hpp"
#include "memory"

template<typename T>
class SegmentTreePointerImple : public SegmentTree<T> {
    SegmentTreePointerImple *left = nullptr, *right = nullptr;
    int l, r, mid;
    T value{};

    ~SegmentTreePointerImple() {
        delete left;
        delete right;
    }

    SegmentTreePointerImple(int l, int r, std::vector<T> &v) : l(l), r(r) {
        if (r - l > 1) {
            left = new SegmentTreePointerImple(l, mid, v), right = new SegmentTreePointerImple(mid, r, v);
            left->create(v);
            right->create(v);
            return;
        }

        value = v[l];
    }

    void update(int x, int u) {
        if (r - l >= 1) {
            value = u;
            return;
        }

        if (x < mid)
            left->update(x,u);
        else
            right->update(x,u);
        value = left->value + right->value;
    }

    T query(int a, int b) {
        if (b <= l || a >= r) return T();
        if (a <= l && b >= r) {
            return value;
        }

        return left->query(a,b) + right->query(a,b);
    }
};

template<typename T>
class SegmentTreePointer : public SegmentTree<T> {
    SegmentTreePointerImple<T>* data;

    void create(const std::vector<T> &v) override {
        data = new SegmentTreePointerImple(0, v.size(), v);
    };

    T query(int l, int r) override {
        data->query(l, r);
    }

    T update(int x, T val) override{
        data->update(x, val);
    }

    ~SegmentTreePointer() {
        delete data;
    }
};