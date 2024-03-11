#ifndef CLASS_FLAGS_H
#define CLASS_FLAGS_H

#pragma once

#include "gflags/gflags.h"
#include <iostream>

class Flags {
public:
  static bool validateFlag_fdisplay(const char *flagname, bool value) {
    std::cout << "validating flag: " << flagname << " value: " << value
              << std::endl;
    return true;
  }

  static bool validateFlag_ftest(const char *flagname, uint32_t value) {
    std::cout << "validating flag: " << flagname << " value: " << value
              << std::endl;
    if (value > 0 && value < 1024) {
      return true;
    }
    return false;
  }

  static bool validateFlag_fstring(const char *flagname,
                                   const std::string &value) {
    std::cout << "validating flag: " << flagname << " value: " << value
              << std::endl;
    return value[0] != '\0';
  }
};

DECLARE_bool(fdisplay);
DECLARE_string(flagstring);
DECLARE_uint32(ftest);

DEFINE_validator(fdisplay, [](const char *flagname, bool value) {
  return Flags::validateFlag_fdisplay(flagname, value);
});

DEFINE_validator(flagstring,
                 [](const char *flagname, const std::string &value) {
                   return Flags::validateFlag_fstring(flagname, value);
                 });

DEFINE_validator(ftest, [](const char *flagname, uint32_t value) {
  return Flags::validateFlag_ftest(flagname, value);
});

#endif
