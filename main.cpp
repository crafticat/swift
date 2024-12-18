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
#include "algo/tester/TesterManager.hpp"
#include "algo/tester/MapTesterManager.hpp"


int main() {

    int siz = 1e5;
    int iter = 1e5;

    TesterManager test;
    auto it = std::make_shared<HashmapTests::InsertionTest>(std::shared_ptr<GPHashmap>());
    test.addTest(it);

    test.run(siz, iter);

    return 0;
}
