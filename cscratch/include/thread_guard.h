#ifndef CLASS_THREAD_GUARD_H
#define CLASS_THREAD_GUARD_H

#include <thread>

class ThreadGuard {
    std::thread &_m_t;
    public:
    ThreadGuard(std::thread& t);

    ~ThreadGuard(); 
    ThreadGuard(ThreadGuard& t) = delete;
    ThreadGuard operator=(const ThreadGuard& t) = delete;
};

#endif