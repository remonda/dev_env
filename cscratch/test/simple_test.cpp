#include "gtest/gtest.h"

TEST(Simple_test, test1) {
    EXPECT_EQ(1,1);
}

TEST(Simple_test, test2) {
    EXPECT_EQ(100,100);
    EXPECT_EQ(100,1);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}