#include "Consumer.h"



Consumer::Consumer(Producer* ptr) : ptr(ptr)
{
    mtx = new std::mutex;
}

Consumer::~Consumer()
{
    delete mtx;
    mtx = nullptr;
}

void Consumer::ThreadRoutine()
{
    while (IsRunning())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        randoms = ptr->Return_Randoms();

        for (std::vector<double>::iterator i = randoms.begin(); i != randoms.end(); i++)
        {
            sum += *i;
        }

        mtx->lock();
        avrg = sum / randoms.size();
        mtx->unlock();
    }
}

double Consumer::Show_Avrg()
{
    return avrg;
}


