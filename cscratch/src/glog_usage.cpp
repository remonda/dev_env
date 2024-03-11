#include "include/glog_usage.h"

void GlogUsage::init(char *appName) {

  // config glog
  FLAGS_log_dir = "./logs";

  // Initialize Google's logging library.
  google::InitGoogleLogging(appName);
  LOG(INFO) << "glog initialisation compelted";
}
