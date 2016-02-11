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
        const ShaderObjectData shaderObjectData("vert", { "valid" });
    });
}

TEST(ShaderObjectDataTest, invalidType) {
    EXPECT_THROW(
        const ShaderObjectData shaderObjectData("invalid_type", { "valid" }),
        InvalidArg
    );
}

TEST(ShaderObjectDataTest, emptySourcePaths) {
    EXPECT_THROW(
        const ShaderObjectData shaderObjectData("vert", {}),
        InvalidArgProperty
    );
}
