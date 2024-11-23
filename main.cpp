#include <bits/stdc++.h>
#include "utils/timer.hpp"
#include "algo/hashmaps/Hashmap.hpp"
#include "algo/hashmaps/STDHashmap.hpp"
#include "algo/hashmaps/GPHashmap.hpp"
#include "algo/hashmaps/VecHashmap.hpp"
#include "algo/hashmaps/SetHashmap.hpp"
#include "algo/sets/Set.hpp"
#include "algo/sets/GNUSet.hpp"
#include "algo/sets/STDSet.hpp"

using namespace std;

int rand(int a, int b) {
    return a + rand() % (b -a + 1);
}

void testInsertionsMap(Hashmap &map, int iterations, const vector<pair<int, int>> &val) {
    Timer timer;
    map.resize(iterations);

    for (int i = 0; i < iterations; ++i) {
        auto [x,y] = val[i];
        map.insert(x,y);
    }
    cout << "Performance of (insertion), type:" << map.getName() << ":\n" << timer.elapsedMilliseconds() << endl;
}

void testQueryMap(Hashmap &map, int iterations, const vector<pair<int, int>> &val) {
    Timer timer;

    for (int i = 0; i < iterations; ++i) {
        int x = val[i].first;
        map.get(x);
    }
    cout << "Performance of (query), type:" << map.getName() << ":\n" << timer.elapsedMilliseconds() << endl;
}

void testInsertionsSet(Set &set, int iterations, const vector<pair<int, int>> &val) {
    Timer timer;

    for (int i = 0; i < iterations; ++i) {
        auto [x,y] = val[i];
        set.insert(x);
    }
    cout << "Performance of (insertion), type:" << set.getName() << ":\n" << timer.elapsedMilliseconds() << endl;
}

void testQuerySet(Set &set, int iterations, const vector<pair<int, int>> &val) {
    Timer timer;

    for (int i = 0; i < iterations; ++i) {
        auto [x,y] = val[i];
        set.lb(x);
    }
    cout << "Performance of (insertion), type:" << set.getName() << ":\n" << timer.elapsedMilliseconds() << endl;
}

vector<pair<int, int>> createTests(int iterations) {
    vector<pair<int, int>> ans(iterations);
    for (int i = 0; i < iterations; ++i) {
        ans[i] = {rand(0, 1e9), rand(0, 1e9)};
    }
    return ans;
}

int main() {

    int iter = 1e7;
    auto tests = createTests(iter);
    GNUSet m1;
    STDSet m2;

    cout << "Running on " << iter << " iterations...\n";
    testInsertionsSet(m1, iter, tests);
    testInsertionsSet(m2, iter, tests);
    testQuerySet(m1, iter, tests);
    testQuerySet(m2, iter, tests);

    return 0;
}
