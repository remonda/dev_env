#include "include/singleton.h"
#include <mutex>
// Singleton *Singleton::get_instance() {
//   static Singleton s;
//   return &s;
// }
std::atomic<Singleton *> Singleton::_m_instance{nullptr};
std::mutex Singleton::_m_mtx;

Singleton *Singleton::get_instance() {
  if (_m_instance == nullptr) {
    std::lock_guard<std::mutex> lk{_m_mtx};
    if (_m_instance == nullptr) {
      _m_instance = new Singleton();
    }
  }
  return _m_instance;
}
int Singleton::get_m_int() { return _m_int; }