#ifndef CLASS_GLOG_USAGE_H
#define CLASS_GLOG_USAGE_H

#include "glog/logging.h"

class GlogUsage {
public:
  GlogUsage() {}
  ~GlogUsage() {}
  GlogUsage(const GlogUsage &t) = delete;
  GlogUsage &operator=(const GlogUsage &t) = delete;
  void init(char *appName);
};

#endif