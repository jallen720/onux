#include <gtest/gtest.h>

#include "resources/utils/filesInDirectory.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using onux::filesInDirectory;
using onux::EmptyStringArg;

TEST(filesInDirectoryTest, emptyDirectory) {
    EXPECT_THROW(
        filesInDirectory("", [](auto _) {}),
        EmptyStringArg
    );
}
