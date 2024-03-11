#ifndef CLASS_SINGLETON_H
#define CLASS_SINGLETON_H

#include <atomic>
#include <cstddef>
#include <mutex>

class Singleton {
public:
  static Singleton *get_instance();
  int get_m_int();
  Singleton &operator=(const Singleton &t) = delete;
  Singleton(const Singleton &t) = delete;

private:
  int _m_int;
  static std::mutex _m_mtx;
  static std::atomic<Singleton *> _m_instance;
  Singleton() { _m_int = 0; }
  Singleton(int i) : _m_int(i) {}

  ~Singleton() { delete _m_instance; }
};

#endif