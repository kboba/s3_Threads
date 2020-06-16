#pragma once
#include <thread>

class IThread 
{
private:
    enum class Status 
    {
        STOPPED,
        RUNNING
    };
    std::thread* thr;
    Status status;
public:
    IThread();
    virtual ~IThread();

    void Start();
    void Stop();
    void Join();
    bool IsRunning();

    virtual void ThreadRoutine() = 0;
};
