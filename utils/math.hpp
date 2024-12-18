#pragma once
#include "random"

namespace utils {
    int rand(int a, int b) {
        return a + std::rand() % (b -a);
    }

    int next2pow(int x) {
        return 1 << 32 - __builtin_clz(x - 1);
    }

    template<typename T>
    int sample(std::vector<T> s) {
        int r = rand(0, s.size());
        return s[r];
    }
}