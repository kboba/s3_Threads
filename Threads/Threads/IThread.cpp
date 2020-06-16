#include "IThread.h"

IThread::IThread() : thr(nullptr), status(IThread::Status::STOPPED) {}

IThread::~IThread() 
{
    Stop();
}

void IThread::Start() 
{
    if (!thr) 
    {
        thr = new std::thread(&IThread::ThreadRoutine, this);
        status = IThread::Status::RUNNING;
    }
}

void IThread::Stop() 
{
    if (thr) 
    {
        status = IThread::Status::STOPPED;
        if(thr->joinable()) 
            thr->join();
        delete thr;
        thr = nullptr;
  }
}

void IThread::Join() 
{
    if (thr) 
    {
        if(thr->joinable()) 
            thr->join();
        status = IThread::Status::STOPPED;
        delete thr;
        thr = nullptr;
    }
}

bool IThread::IsRunning() 
{
    return status == IThread::Status::RUNNING;
}
