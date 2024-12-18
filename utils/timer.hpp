#pragma once

#include <chrono>

namespace utils {
    class Timer {
    public:
        Timer() : start_time_point(std::chrono::high_resolution_clock::now()) {}

        void reset() {
            start_time_point = std::chrono::high_resolution_clock::now();
        }

        double elapsedMilliseconds() const {
            return std::chrono::duration<double, std::milli>(
                    std::chrono::high_resolution_clock::now() - start_time_point
            ).count();
        }

        double elapsedSeconds() const {
            return std::chrono::duration<double>(
                    std::chrono::high_resolution_clock::now() - start_time_point
            ).count();
        }

    private:
        std::chrono::high_resolution_clock::time_point start_time_point;
    };

}