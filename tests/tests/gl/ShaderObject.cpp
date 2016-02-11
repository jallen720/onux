#include "gl/ShaderObject.hpp"

#include "fixtures/gl/ShaderObjectTest.hpp"
#include "utils/expectNoThrow.hpp"
#include "utils/testShaderSourcePath.hpp"
#include "graphics/ShaderSource.hpp"
#include "exceptions/Error.hpp"
#include "exceptions/argErrors/ArgFailedRequirement.hpp"
#include "exceptions/argErrors/InvalidArgProperty.hpp"

using onux::ShaderObject;
using onux::ShaderSource;
using onux::Error;
using onux::ArgFailedRequirement;
using onux::InvalidArgProperty;

TEST_F(ShaderObjectTest, validCreation) {
    const ShaderSource validSource(testShaderSourcePath("valid.vert"));

    expectNoThrow([&validSource] {
        ShaderObject({
            &validSource,
        });
    });
}

TEST_F(ShaderObjectTest, noSources) {
    EXPECT_THROW(ShaderObject({}), InvalidArgProperty);
}

TEST_F(ShaderObjectTest, differentSourceTypes) {
    const ShaderSource invalidSources[] {
        { testShaderSourcePath("valid.vert") },
        { testShaderSourcePath("valid.frag") },
    };

    EXPECT_THROW(
        ShaderObject({
            &invalidSources[0],
            &invalidSources[1],
        }),
        ArgFailedRequirement
    );
}

TEST_F(ShaderObjectTest, compilationFailure) {
    const ShaderSource invalidSources[] {
        { testShaderSourcePath("valid.vert")   },
        { testShaderSourcePath("invalid.vert") },
    };

    EXPECT_THROW(
        ShaderObject({
            &invalidSources[0],
            &invalidSources[1],
        }),
        Error
    );
}
