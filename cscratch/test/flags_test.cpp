#include "gtest/gtest.h"
#include "gflags/gflags.h"

#include "include/flags.h"

DEFINE_bool(fdisplay, true, "set if the message will be displayed");

DEFINE_uint32(ftest, 11, "set the test value flag to uint32 11");

DEFINE_string(flagstring, "TEST_SRING", "set the string value flag to TEST_SRING");

int main(int argc, char* argv[]) {

  testing::InitGoogleTest(&argc, argv);

  gflags::ParseCommandLineFlags(&argc, &argv, true);
  gflags::ShutDownCommandLineFlags();

  return RUN_ALL_TESTS();
}

TEST(Flags_test, test1) { EXPECT_TRUE(FLAGS_fdisplay); }
