#pragma once
#include <mutex>
#include <vector>
#include <chrono>

#include "Producer.h"

class Consumer : public IThread
{
    std::mutex* mtx;
    Producer* ptr;
    double avrg, sum;
    std::vector<double> randoms;

public:
    Consumer(Producer* ptr);
    ~Consumer();

    void ThreadRoutine();
    double Show_Avrg();
};

