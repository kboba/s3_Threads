#include "Integrator.h"


Integrator::Integrator() : status(Status::IDLE), step(0) {}

Integrator::~Integrator() {}

void Integrator::SetStatus(Status new_status)
{
    statusMutex.lock();
    status = new_status;
    statusMutex.unlock();
}

void Integrator::ThreadRoutine()
{
    while ( IsRunning() )
    {
        std::this_thread::yield();

        if (GetStatus() == Status::WORKING)
        {
            resultMutex.lock();
            dataMutex.lock();
            for (std::vector<double>::const_iterator i = data.begin(); i != data.end(); i++)
            {
                result += *i * step;
            }
            resultMutex.unlock();
            dataMutex.unlock();

            SetStatus(Status::IDLE);
        }
    }
}

void Integrator::Count(const std::vector<double>& our_data, const double our_step)
{
    SetStatus(Status::WORKING);
    dataMutex.lock();
    data = our_data;
    step = our_step;
    dataMutex.unlock();
}

Integrator::Status Integrator::GetStatus()
{
    return status;
}

double Integrator::GetResult()
{
    return result;
}
