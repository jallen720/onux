#include "graphics/ShaderSource.hpp"

#include "fixtures/ShaderSourceTest.hpp"
#include "testHelpers.hpp"
#include "utils/helpers.hpp"
#include "exceptions/argErrors/InvalidArgProperty.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using std::string;
using onux::ShaderSource;
using onux::readFile;
using onux::InvalidArgProperty;
using onux::EmptyStringArg;

TEST_F(ShaderSourceTest, validCreation) {
  expectNoThrow([] {
    const ShaderSource shaderSource(testShaderPath("valid.vert"));
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
  return ShaderSource(testShaderPath("valid." + type)).getType();
}

TEST_F(ShaderSourceTest, correctTypes) {
  for (auto type : ShaderSource::TYPES) {
    EXPECT_EQ(type.second, shaderSourceType(type.first));
  }
}

TEST_F(ShaderSourceTest, correctSources) {
  const string shaderPath = testShaderPath("valid.vert");
  const ShaderSource shaderSource(shaderPath);
  EXPECT_EQ(readFile(shaderPath), shaderSource.getCode());
}
