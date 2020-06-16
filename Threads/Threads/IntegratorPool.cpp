#include "IntegratorPool.h"

IntegratorPool::IntegratorPool(int number)
{
    for (int i = 0; i < number; i++)
    {
        pool.push_back(new Integrator());
        pool[i]->Start();
    }
}

IntegratorPool::~IntegratorPool()
{    
    for (int i = pool.size() - 1; i >= 0; i--)
    {
        pool[i]->Stop();
        delete pool[i];
        pool.pop_back();
    }
}

Integrator* IntegratorPool::GetInstance()
{
    for (size_t i = 0; i < pool.size(); i++)
    {
        if (pool[i]->GetStatus() == Integrator::Status::IDLE)
            return pool[i];
        else
            return nullptr;
        if (i == pool.size() - 1)
            i = 0;
    }
}

size_t IntegratorPool::GetLoad()
{
    size_t working=0;

    for (size_t i = 0; i < pool.size(); i++)
    {
        if (pool[i]->GetStatus() == Integrator::Status::WORKING)
            working++;
    }

    return working;
}
