#include "resources/ResourceManager.hpp"

#include <string>
#include <gtest/gtest.h>
#include <boost/filesystem.hpp>

#include "tests/utils/expectNoThrow.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using std::string;
using boost::filesystem::filesystem_error;
using onux::ResourceManager;
using onux::EmptyStringArg;

TEST(ResourceManagerTest, validCreation) {
    static const string VALID_RESOURCES_DIRECTORY = "tests/resources/valid/";

    expectNoThrow([&] {
        ResourceManager { VALID_RESOURCES_DIRECTORY };
    });
}

TEST(ResourceManagerTest, emptyResourcesDirectory) {
    EXPECT_THROW(ResourceManager(""), EmptyStringArg);
}

TEST(ResourceManagerTest, invalidResourcesDirectory) {
    EXPECT_THROW(
        ResourceManager("invalid/resources/directory/"),
        filesystem_error
    );
}
