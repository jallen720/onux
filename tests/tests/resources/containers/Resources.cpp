#include <gtest/gtest.h>

#include "resources/containers/ShaderSources.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using onux::ShaderSources;
using onux::EmptyStringArg;

TEST(ResourcesTest, emptyRelativePath) {
    EXPECT_THROW(ShaderSources()[""], EmptyStringArg);
}
