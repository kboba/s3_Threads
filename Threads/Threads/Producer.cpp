#include <random>

#include "Producer.h"

std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_real_distribution< double > distribution(0.0, 1.0);
double random_value()
{
    return distribution(generator);
}
double random_value(double min, double max)
{
    return random_value() * (max - min) + min;
}

Producer::Producer()
{
    mtx = new std::mutex;
}

Producer::~Producer()
{
    delete mtx;
    mtx = nullptr;
}

void Producer::ThreadRoutine()
{
    while ( IsRunning() )
    {
        double random = random_value(0, 100);
        mtx->lock();
        randoms.push_back(random);
        mtx->unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

std::vector<double> Producer::Return_Randoms()
{
    return randoms;
}
