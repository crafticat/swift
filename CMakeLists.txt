cmake_minimum_required(VERSION 3.28)
project(hash)

set(CMAKE_CXX_STANDARD 17)

add_executable(hash main.cpp
        utils/timer.hpp
        algo/hashmaps/Hashmap.hpp
        algo/hashmaps/STDHashmap.hpp
        algo/hashmaps/GPHashmap.hpp
        algo/hashmaps/VecHashmap.hpp
        algo/hashmaps/SetHashmap.hpp
        algo/sets/Set.hpp
        algo/sets/STDSet.hpp
        algo/sets/GNUSet.hpp
        algo/tester/MapTesterManager.hpp
        algo/tester/Tester.hpp
        algo/tester/TestResults.hpp
        utils/math.hpp
        utils/Settings.hpp
        algo/tester/TesterManager.hpp
        algo/segments_tree/SegmentTree.hpp
        algo/segments_tree/SegmentTreePointer.hpp
        algo/segments_tree/SegmentTreeIter.hpp
        algo/tester/SegmentTreeTesterManager.hpp)
