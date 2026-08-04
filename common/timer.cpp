#include "timer.h"

using namespace std::chrono;

void Timer::start()
{
    startTime = high_resolution_clock::now();
}

long long Timer::stop()
{
    auto endTime = high_resolution_clock::now();

    return duration_cast<microseconds>(endTime - startTime).count();
}