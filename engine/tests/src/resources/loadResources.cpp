#include <gtest/gtest.h>
#include <boost/filesystem.hpp>

#include "resources/loadResources.hpp"
#include "resources/ShaderSource.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using std::string;
using boost::filesystem::filesystem_error;
using onux::loadResources;
using onux::ShaderSource;
using onux::EmptyStringArg;

TEST(loadResourcesTest, emptyDirectory) {
    EXPECT_THROW(loadResources<ShaderSource>(""), EmptyStringArg);
}

TEST(loadResourcesTest, invalidDirectory) {
    EXPECT_THROW(loadResources<ShaderSource>("invalid/directory"), filesystem_error);
}
