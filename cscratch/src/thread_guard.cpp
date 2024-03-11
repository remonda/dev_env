#include "include/thread_guard.h"

ThreadGuard::ThreadGuard(std::thread &t) : _m_t(t) {}
ThreadGuard::~ThreadGuard() {
  if (_m_t.joinable()) {
    _m_t.join();
  }
}