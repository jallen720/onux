#include "utils/readFile.hpp"

#include "utils/values.hpp"

#include <gtest/gtest.h>

#include "utils/expectNoThrow.hpp"
#include "utils/testShaderSourcePath.hpp"
#include "exceptions/Error.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using onux::readFile;
using onux::Error;
using onux::EmptyStringArg;

TEST(readFileTest, validFile) {
    expectNoThrow([] {
        readFile(testShaderSourcePath("valid.vert"));
    });
}

TEST(readFileTest, invalidFile) {
    EXPECT_THROW(readFile("does_not_exist"), Error);
}

TEST(readFileTest, emptyPath) {
    EXPECT_THROW(readFile(""), EmptyStringArg);
}
