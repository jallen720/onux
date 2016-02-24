#include <gtest/gtest.h>
#include <boost/filesystem.hpp>

#include "resources/utils/filesInDirectory.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using std::string;
using boost::filesystem::filesystem_error;
using onux::filesInDirectory;
using onux::EmptyStringArg;

TEST(filesInDirectoryTest, emptyDirectory) {
    EXPECT_THROW(filesInDirectory("", {}), EmptyStringArg);
}

TEST(filesInDirectoryTest, invalidDirectory) {
    EXPECT_THROW(filesInDirectory("invalid/directory", {}), filesystem_error);
}
