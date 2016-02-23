#include "resources/ShaderSource.hpp"

#include "tests/fixtures/resources/ShaderSourceTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "tests/utils/validResourcePath.hpp"
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
        ShaderSource::create(validResourcePath("shaderSources", "valid.vert"));
    });
}

TEST_F(ShaderSourceTest, invalidFileExtension) {
    EXPECT_THROW(ShaderSource::create("invalid.ext"), InvalidArgProperty);
}

TEST_F(ShaderSourceTest, emptyPath) {
    EXPECT_THROW(ShaderSource::create(""), EmptyStringArg);
}

static GLenum shaderSourceType(const string& type) {
    return ShaderSource::create(validResourcePath("shaderSources", "valid." + type))->getType();
}

TEST_F(ShaderSourceTest, correctTypes) {
    for (const ShaderSource::Types::value_type& type : ShaderSource::TYPES) {
        EXPECT_EQ(type.second, shaderSourceType(type.first));
    }
}

TEST_F(ShaderSourceTest, correctSources) {
    const string validShaderSourcePath = validResourcePath("shaderSources", "valid.vert");

    EXPECT_EQ(
        File(validShaderSourcePath).getContents(),
        ShaderSource::create(validShaderSourcePath)->getCode()
    );
}
