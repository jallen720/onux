#include "ShaderSource.hpp"

#include <stdexcept>

#include "fixtures/ShaderSourceTest.hpp"
#include "testUtil.hpp"
#include "helpers.hpp"

using std::runtime_error;

TEST_F(ShaderSourceTest, validCreation) {
  expectNoThrow([] {
    ShaderSource(testShaderPath("valid.vert"));
  });
}

TEST_F(ShaderSourceTest, invalidFileExtensions) {
  EXPECT_THROW(
    ShaderSource("invalid.ext"),
    runtime_error
  );

  EXPECT_THROW(
    ShaderSource(""),
    runtime_error
  );
}

TEST_F(ShaderSourceTest, correctTypes) {
  for (auto type : ShaderSource::types) {
    EXPECT_EQ(
      type.second,
      ShaderSource(testShaderPath("valid." + type.first)).getType()
    );
  }
}

TEST_F(ShaderSourceTest, correctSources) {
  const string shader = testShaderPath("valid.vert");

  EXPECT_EQ(
    readFile(shader),
    ShaderSource(shader).getCode()
  );
}


