#include <iostream>
#include <chrono>
#include <mutex>
#include <vector>
#include <conio.h>

#include "IThread.h"
#include "Producer.h"
#include "Consumer.h"
#include "Integrator.h"
#include "IntegratorPool.h"


class SimpleThread : public IThread 
{
    int id;
    int counter;
    std::mutex* mtx;
public:
    SimpleThread(int id, std::mutex* mtx) : id(id), counter(0), mtx(mtx) {}

    void ThreadRoutine() 
    {
        while (IsRunning()) 
        {
            mtx->lock();
            std::cout << "Thread: " << id << ", counter: " << counter++ << std::endl;
            mtx->unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

int main() 
{
    std::vector<SimpleThread*> v;
    std::mutex mtx;
  
    for (int i = 0; i < 20; ++i) 
    {
        auto t = new SimpleThread(i, &mtx);
        t->Start();
        v.push_back(t);
    }

    while (1) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
