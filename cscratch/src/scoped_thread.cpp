#include "include/scoped_thread.h"

ScopedThread::ScopedThread(std::thread t) : _m_t(std::move(t)) {
  if (!_m_t.joinable()) {
    throw std::logic_error("No Thread");
  }
}

ScopedThread::~ScopedThread() { _m_t.join(); }
