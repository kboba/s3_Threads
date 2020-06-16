#pragma once
#include <mutex>
#include <vector>

#include "IThread.h"

class Integrator : public IThread
{
public:
    enum class Status
    {
        IDLE,
        WORKING
    };

private:
    std::vector<double> data;
    double step;
    std::mutex dataMutex;
    std::mutex statusMutex;
    std::mutex resultMutex;
    Status status;
    double result;

    void SetStatus(Status);
    void ThreadRoutine();

public:
    Integrator();
    ~Integrator();

    void Count(const std::vector<double>&, const double);
    Status GetStatus();
    double GetResult();
};
