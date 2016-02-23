#include "gl/ShaderObject.hpp"

#include "tests/fixtures/gl/ShaderObjectTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "tests/utils/validResourcePath.hpp"
#include "tests/utils/invalidResourcePath.hpp"
#include "resources/ShaderSource.hpp"
#include "exceptions/Error.hpp"
#include "exceptions/argErrors/ArgFailedRequirement.hpp"
#include "exceptions/argErrors/InvalidArgProperty.hpp"

using onux::ShaderObject;
using onux::ShaderSource;
using onux::Error;
using onux::ArgFailedRequirement;
using onux::InvalidArgProperty;

TEST_F(ShaderObjectTest, validCreation) {
    const ShaderSource::Ptr validSource =
        ShaderSource::create(validResourcePath("shaderSources", "valid.vert"));

    expectNoThrow([&] {
        ShaderObject::create({
            validSource.get(),
        });
    });
}

TEST_F(ShaderObjectTest, noSources) {
    EXPECT_THROW(ShaderObject::create({}), InvalidArgProperty);
}

TEST_F(ShaderObjectTest, differentSourceTypes) {
    const ShaderSource::Ptr differentSources[] {
        ShaderSource::create(validResourcePath("shaderSources", "valid.vert")),
        ShaderSource::create(validResourcePath("shaderSources", "valid.frag")),
    };

    EXPECT_THROW(
        ShaderObject::create({
            differentSources[0].get(),
            differentSources[1].get(),
        }),
        ArgFailedRequirement
    );
}

TEST_F(ShaderObjectTest, compilationFailure) {
    const ShaderSource::Ptr invalidSources[] {
        ShaderSource::create(validResourcePath("shaderSources", "valid.vert")),
        ShaderSource::create(invalidResourcePath("shaderSources", "invalid.vert")),
    };

    EXPECT_THROW(
        ShaderObject::create({
            invalidSources[0].get(),
            invalidSources[1].get(),
        }),
        Error
    );
}
