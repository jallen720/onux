#include "utils/helpers.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "testHelpers.hpp"

using std::runtime_error;
using onux::readFile;
using onux::fileExtension;

TEST(utilsHelpersTest, readValidFile) {
  expectNoThrow([] {
    readFile(testShaderPath("valid.vert"));
  });
}

TEST(utilsHelpersTest, readInvalidFile) {
  EXPECT_THROW(
    readFile(""),
    runtime_error
  );
}

TEST(utilsHelpersTest, validFileExtension) {
  EXPECT_EQ("cpp", fileExtension("valid.cpp"));
  EXPECT_EQ("js", fileExtension("valid.spec.js"));
}

TEST(utilsHelpersTest, noFileExtension) {
  EXPECT_EQ("", fileExtension("noExtension"));
}
