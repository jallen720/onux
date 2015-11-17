#include "utils/helpers.hpp"

#include <gtest/gtest.h>

#include "testHelpers.hpp"
#include "exceptions/Error.hpp"

using onux::readFile;
using onux::fileExtension;
using onux::Error;

TEST(utilsHelpersTest, readValidFile) {
  expectNoThrow([] {
    readFile(testShaderPath("valid.vert"));
  });
}

TEST(utilsHelpersTest, readInvalidFile) {
  EXPECT_THROW(
    readFile(""),
    Error
  );
}

TEST(utilsHelpersTest, validFileExtension) {
  EXPECT_EQ("cpp", fileExtension("valid.cpp"));
  EXPECT_EQ("js", fileExtension("valid.spec.js"));
}

TEST(utilsHelpersTest, noFileExtension) {
  EXPECT_EQ("", fileExtension("noExtension"));
}
