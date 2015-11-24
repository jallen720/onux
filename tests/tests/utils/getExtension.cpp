#include "utils/getExtension.hpp"

#include <gtest/gtest.h>

using onux::getExtension;

TEST(getExtensionTest, validExtension) {
  EXPECT_EQ("cpp", getExtension("valid.cpp"));
  EXPECT_EQ("js", getExtension("valid.spec.js"));
}

TEST(getExtensionTest, noExtension) {
  EXPECT_EQ("", getExtension("noExtension"));
}
