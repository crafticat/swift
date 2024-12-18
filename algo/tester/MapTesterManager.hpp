#pragma once

#include <vector>
#include <memory>
#include "../hashmaps/Hashmap.hpp"
#include "Tester.hpp"
#include "../../utils/math.hpp"
#include "../../utils/Settings.hpp"
#include "../../utils/timer.hpp"

namespace HashmapTests {
    class InsertionTest : public Tester {
        std::shared_ptr<Hashmap> map;

    public:
        InsertionTest(std::shared_ptr<Hashmap> m) : map(m) {}

        TestResults run(int size) override {
            for (int i = 0; i < size; i++) {
                map->insert(utils::rand(0, utils::MAX_VALUE), utils::rand(0, utils::MAX_VALUE));
            }

            std::vector<std::pair<int, int>> tests(iter);
            for (auto &[x, y]: tests)
                x = utils::rand(0, utils::MAX_VALUE), y = utils::rand(0, utils::MAX_VALUE);

            utils::Timer timer;

            for (const auto &[a, b]: tests) {
                map->insert(a, b);
            }

            return {timer.elapsedSeconds(), size};
        }
    };

    class SearchTest : public Tester {
        std::shared_ptr<Hashmap> map;

    public:
        SearchTest(std::shared_ptr<Hashmap> m) : map(m) {}

        TestResults run(int size) override {
            std::vector<int> values;
            for (int i = 0; i < size; i++) {
                int x = utils::rand(0, utils::MAX_VALUE);
                map->insert(utils::rand(0, utils::MAX_VALUE), x);
                values.push_back(x);
            }

            std::vector<int> tests;
            for (int i = 0; i < iter; i++) {
                int v = utils::sample(values);
                tests.push_back(v);
            }

            utils::Timer timer;

            for (const auto &a: tests) {
                map->get(a);
            }

            return {timer.elapsedSeconds(), size};
        }
    };
}