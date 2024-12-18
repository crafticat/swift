#pragma once

class TestResults {
    int siz;
    double seconds;
public:
    TestResults(double seconds, int siz) : seconds(seconds), siz(siz) {}
};