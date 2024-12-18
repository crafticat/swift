#pragma once

#include "Tester.hpp"
#include "../segments_tree/SegmentTree.hpp"
#include <memory>
#include "../../utils/timer.hpp"

template<typename T>
class CreationTest : public Tester {
    std::shared_ptr<SegmentTree<T>> segmentTree;

public:
    CreationTest(std::shared_ptr<SegmentTree<T>> st) : segmentTree(move(st)) {}

    TestResults run(int siz) override {
        std::vector<std::vector<T>> values(iter, std::vector<T>(siz));
        for(auto& v : values) {
            for (auto &e: v)
                e = T::rand();
        }

        utils::Timer timer;

        for(auto& v : values)
            segmentTree->generate(v);

        return {iter, timer.elapsedSeconds()};
    }
};

template<typename T>
class queryTest : public Tester {
    std::shared_ptr<SegmentTree<T>> segmentTree;

public:
    queryTest(std::shared_ptr<SegmentTree<T>> st) : segmentTree(move(st)) {}

    TestResults run(int siz) override {
        std::vector<T> v(siz);
        for(auto& e : v)
            e = T::rand();

        segmentTree->generate(v);

        std::vector<std::pair<T, T>> queries(iter);
        for(auto& [l, r] : queries)
            l = rand(0, segmentTree->size), r = rand(l + 1, segmentTree->size + 1);

        utils::Timer timer;

        for(const auto [l, r] : queries)
            segmentTree->query(l, r);

        return {iter, timer.elapsedSeconds()};
    }
};

template<typename T>
class updateTest : public Tester {
    std::shared_ptr<SegmentTree<T>> segmentTree;

public:
    updateTest(std::shared_ptr<SegmentTree<T>> st) : segmentTree(move(st)) {}

    TestResults run(int siz) override {
        std::vector<T> v(siz);
        for(auto& e : v)
            e = T::rand();

        segmentTree->generate(v);

        std::vector<std::pair<int, T>> updates(iter);
        for(auto& [x, vals] : updates)
            x = rand(0, segmentTree->size), vals = T::rand();

        utils::Timer timer;

        for(const auto [l, r] : updates)
            segmentTree->query(l, r);

        return {iter, timer.elapsedSeconds()};
    }
};