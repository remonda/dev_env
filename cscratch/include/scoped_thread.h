#ifndef CLASS_SCOPED_THREAD_H
#define CLASS_SCOPED_THREAD_H

#include <stdexcept>
#include <thread>
#include <utility>


class ScopedThread {
  std::thread _m_t;

public:
  explicit ScopedThread(std::thread t);
  ~ScopedThread();
  ScopedThread(ScopedThread const &t) = delete;
  ScopedThread operator=(ScopedThread const &t) = delete;
};

#endif