#include "glog/logging.h"
#include "gflags/gflags.h"
#include "include/glog_usage.h"
#include "include/scoped_thread.h"
#include "include/singleton.h"
#include "include/thread_guard.h"
#include "include/thread_wrapper.h"
#include "include/flags.h"

#include <exception>
#include <iostream>
#include <thread>
#include <typeinfo>


void init(char *appName) {
  GlogUsage gu;
  gu.init(appName);
}

void do_something_in_main() {
  std::cout << "do something in the main function" << std::endl;
}

int main(int argc, char *argv[]) {
// gflags

  gflags::ParseCommandLineFlags(&argc, &argv, true);

  gflags::ShutDownCommandLineFlags();

  init(argv[0]);

  std::cout << "Hello World in Docker Container" << std::endl;

  std::cout << "The max number of thread can be run in the machine: "
            << std::thread::hardware_concurrency() << std::endl;
  std::cout << "print out the parameters of the application" << std::endl;
  for (int i = 0; i < argc; i++) {
    std::cout << "the parameter: " << argc << " value: " << argv[i]
              << std::endl;
  }

  std::cout << "parameters print end" << std::endl;

  Singleton *s = Singleton::get_instance();
  std::cout << "value: " << s->get_m_int() << std::endl;
  LOG(INFO) << "Hello World in glog" << std::endl;

  ThreadWrapper thread_task;
  std::thread my_thread(thread_task);
  // an exception safe way by the RAII (Resource Acquisition Is Initialization)
  ThreadGuard g(my_thread);
  do_something_in_main();

  // need to exit the thread if the main thread encounters some exception
  // try {
  //   do_something_in_main();
  // } catch (...) {
  //   my_thread.join();
  //   throw;
  // }
  // if (my_thread.joinable()) {
  //   my_thread.join();
  //   // my_thread.detach();
  // }

  if(FLAGS_fdisplay) {
    std::cout << "display the message if the flag fdisplay is ture" << std::endl;
  }

  if(FLAGS_ftest) {
    std::cout << "display the message if the flag ftest is in the given range 0-1024" <<std::endl;
  }

  if(FLAGS_flagstring == "TEST_SRING") {
    std::cout << "display the message if the flag fstring is the given value" <<std::endl;
  }

  std::cout << "app end" << std::endl;
  return 0;
}

