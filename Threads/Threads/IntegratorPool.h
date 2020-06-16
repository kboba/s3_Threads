#pragma once
#include "Integrator.h"

class IntegratorPool
{
    std::vector<Integrator*> pool;
public:
    IntegratorPool(int);
    ~IntegratorPool();

    Integrator* GetInstance();
    size_t GetLoad();
};
