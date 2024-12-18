#pragma once

#include <memory>
#include <vector>
#include "Tester.hpp"

class TesterManager {
    std::vector<std::shared_ptr<Tester>> tests;

public:
    void addTest(std::shared_ptr<Tester> test) {
        tests.push_back(std::move(test));
    }

    std::vector<TestResults> run(int size, int iter) {
        std::vector<TestResults> results;
        for (const auto& test : tests) {
            test->iter = iter;
            results.push_back(test->run(size));
        }

        return results;
    }
};