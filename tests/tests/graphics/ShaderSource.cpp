#include "graphics/ShaderSource.hpp"

#include "fixtures/graphics/ShaderSourceTest.hpp"
#include "utils/expectNoThrow.hpp"
#include "utils/testShaderSourcePath.hpp"
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
        const ShaderSource shaderSource(testShaderSourcePath("valid.vert"));
    });
}

TEST_F(ShaderSourceTest, invalidFileExtension) {
    EXPECT_THROW(
        const ShaderSource shaderSource("invalid.ext"),
        InvalidArgProperty
    );
}

TEST_F(ShaderSourceTest, emptyPath) {
    EXPECT_THROW(
        const ShaderSource shaderSource(""),
        EmptyStringArg
    );
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
    const ShaderSource shaderSource(shaderPath);

    EXPECT_EQ(
        File(shaderPath).getContents(),
        shaderSource.getCode()
    );
}
