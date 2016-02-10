#include <gtest/gtest.h>

#include "resources/utils/filesInDirectory.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using std::string;
using onux::filesInDirectory;
using onux::EmptyStringArg;

TEST(filesInDirectoryTest, emptyDirectory) {
    EXPECT_THROW(
        filesInDirectory("", [](const string& _) {}),
        EmptyStringArg
    );
}
