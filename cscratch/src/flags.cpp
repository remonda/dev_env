#include "include/flags.h"

#include <iostream>

DEFINE_bool(fdisplay, true, "set if the message will be displayed");

DEFINE_uint32(ftest, 11, "set the test value flag to uint32 11");

DEFINE_string(flagstring, "TEST_SRING",
              "set the string value flag to TEST_SRING");

