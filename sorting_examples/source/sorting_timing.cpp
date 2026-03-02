#include <chrono>
#include "sorting.h"
#include <iostream>
#include <random>

typedef std::chrono::high_resolution_clock timingClock;

double t_seconds(std::chrono::time_point<timingClock> t1, std::chrono::time_point<timingClock> t2)
{
    return (t2 - t1).count() / 1e9;
}

int main()
{

    return 0;
}