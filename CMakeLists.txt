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
        algo/sets/GNUSet.hpp)
