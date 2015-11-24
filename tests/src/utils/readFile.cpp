#include "utils/readFile.hpp"

#include <gtest/gtest.h>

#include "testHelpers.hpp"
#include "exceptions/Error.hpp"

using onux::readFile;
using onux::Error;

TEST(readFileTest, validFile) {
  expectNoThrow([] {
    readFile(testShaderPath("valid.vert"));
  });
}

TEST(readFileTest, invalidFile) {
  EXPECT_THROW(
    readFile(""),
    Error
  );
}
