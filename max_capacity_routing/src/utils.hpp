#pragma once
#include <chrono>
using namespace std;

using Clock = chrono::high_resolution_clock;
using TimePoint = chrono::time_point<Clock>;

double elapsed(TimePoint start) {
    return chrono::duration<double>(Clock::now() - start).count();
}
