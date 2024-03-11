#ifndef CLASS_SINGLETON_H
#define CLASS_SINGLETON_H

#include <iostream>

class Singleton {
public:
  static Singleton *get_instance();

  Singleton(const Singleton &) = delete;

  Singleton &operator=(const Singleton &) = delete;

  ~Singleton() { delete _m_instance; }

  void print();

private:
  static Singleton *_m_instance;
  Singleton();
  int _m_int;
};

#endif // !CLASS_SINGLETON_H
