#include "graphics/ShaderSource.hpp"

#include <stdexcept>

#include "fixtures/ShaderSourceTest.hpp"
#include "testUtil.hpp"
#include "helpers.hpp"

using std::runtime_error;
using std::string;
using onux::ShaderSource;
using onux::readFile;

TEST_F(ShaderSourceTest, validCreation) {
  expectNoThrow([] {
    const ShaderSource shaderSource(testShaderPath("valid.vert"));
  });
}

TEST_F(ShaderSourceTest, invalidFileExtensions) {
  EXPECT_THROW(
    const ShaderSource shaderSource("invalid.ext"),
    runtime_error
  );

  EXPECT_THROW(
    const ShaderSource shaderSource(""),
    runtime_error
  );
}

static GLenum shaderSourceType(const string& type) {
  const ShaderSource shaderSource(testShaderPath("valid." + type));
  return shaderSource.getType();
}

TEST_F(ShaderSourceTest, correctTypes) {
  for (auto type : ShaderSource::TYPES) {
    EXPECT_EQ(type.second, shaderSourceType(type.first));
  }
}

TEST_F(ShaderSourceTest, correctSources) {
  const string shader = testShaderPath("valid.vert");
  const ShaderSource shaderSource(shader);
  EXPECT_EQ(readFile(shader), shaderSource.getCode());
}


