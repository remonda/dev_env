#include "include/flags.h"

#include <algorithm>
#include <iostream>
#include <list>
#include <mutex>

std::list<int> g_list_int;
std::mutex g_mutex;

void add_to_list(int val) {
  std::lock_guard<std::mutex> guard(g_mutex);
  g_list_int.push_back(val);
}

bool list_contains(int val_to_find) {
  std::lock_guard<std::mutex> guard(g_mutex);
  return std::find(g_list_int.begin(), g_list_int.end(), val_to_find) !=
         g_list_int.end();
}

void print_f() {
  if (FLAGS_fdisplay) {
    std::cout << "can use the gflags here " << std::endl;
  }
}