#include "resources/files/ShaderObjectData.hpp"

#include <gtest/gtest.h>

#include "utils/expectNoThrow.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"
#include "exceptions/argErrors/InvalidArgProperty.hpp"

using onux::ShaderObjectData;
using onux::InvalidArg;
using onux::InvalidArgProperty;

TEST(ShaderObjectDataTest, validCreation) {
    expectNoThrow([] {
        ShaderObjectData("vert", { "valid" });
    });
}

TEST(ShaderObjectDataTest, invalidType) {
    EXPECT_THROW(ShaderObjectData("invalid_type", { "valid" }), InvalidArg);
}

TEST(ShaderObjectDataTest, emptySourcePaths) {
    EXPECT_THROW(ShaderObjectData("vert", {}), InvalidArgProperty);
}
