#include "utils/helpers.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "testHelpers.hpp"

using std::runtime_error;
using onux::readFile;
using onux::fileExtension;

TEST(helpersTest, readValidFile) {
  expectNoThrow([] {
    readFile(testShaderPath("valid.vert"));
  });
}

TEST(helpersTest, readInvalidFile) {
  EXPECT_THROW(
    readFile(""),
    runtime_error
  );
}

TEST(helpersTest, validFileExtension) {
  EXPECT_EQ("cpp", fileExtension("valid.cpp"));
  EXPECT_EQ("js", fileExtension("valid.spec.js"));
}

TEST(helpersTest, noFileExtension) {
  EXPECT_EQ("", fileExtension("noExtension"));
}
