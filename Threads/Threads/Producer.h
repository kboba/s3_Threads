#pragma once

#include <mutex>
#include <vector>
#include <chrono>

#include "IThread.h"

class Producer : public IThread
{
    std::mutex* mtx;
    std::vector<double> randoms;

public:
    Producer();
    ~Producer();

    void ThreadRoutine();
    std::vector<double> Return_Randoms();
};
