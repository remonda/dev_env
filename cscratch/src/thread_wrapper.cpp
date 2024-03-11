#include "include/thread_wrapper.h"
#include <iostream>

void do_something() {
  std::cout << "do something in the thread" << std::endl;
}

void do_something_else() {
  std::cout << "do something else in the thread" << std::endl;
}

void ThreadWrapper::operator()() const {
  do_something();
  do_something_else();
}
