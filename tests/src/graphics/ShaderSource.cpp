#include "graphics/ShaderSource.hpp"

#include "tests/fixtures/graphics/ShaderSourceTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "tests/utils/testShaderSourcePath.hpp"
#include "utils/File.hpp"
#include "exceptions/argErrors/InvalidArgProperty.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using std::string;
using onux::ShaderSource;
using onux::File;
using onux::InvalidArgProperty;
using onux::EmptyStringArg;

TEST_F(ShaderSourceTest, validCreation) {
    expectNoThrow([] {
        ShaderSource(testShaderSourcePath("valid.vert"));
    });
}

TEST_F(ShaderSourceTest, invalidFileExtension) {
    EXPECT_THROW(ShaderSource("invalid.ext"), InvalidArgProperty);
}

TEST_F(ShaderSourceTest, emptyPath) {
    EXPECT_THROW(ShaderSource(""), EmptyStringArg);
}

static GLenum shaderSourceType(const string& type) {
    return ShaderSource(testShaderSourcePath("valid." + type)).getType();
}

TEST_F(ShaderSourceTest, correctTypes) {
    for (const ShaderSource::Types::value_type& type : ShaderSource::TYPES) {
        EXPECT_EQ(type.second, shaderSourceType(type.first));
    }
}

TEST_F(ShaderSourceTest, correctSources) {
    const string shaderPath = testShaderSourcePath("valid.vert");

    EXPECT_EQ(
        File(shaderPath).getContents(),
        ShaderSource(shaderPath).getCode()
    );
}
