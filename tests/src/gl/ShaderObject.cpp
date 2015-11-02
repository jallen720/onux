#include "gl/ShaderObject.hpp"

#include <stdexcept>

#include "fixtures/ShaderObjectTest.hpp"
#include "testHelpers.hpp"
#include "graphics/ShaderSource.hpp"

using std::runtime_error;
using onux::ShaderSource;
using onux::ShaderObject;

TEST_F(ShaderObjectTest, validCreation) {
  const ShaderSource validSource(testShaderPath("valid.vert"));

  expectNoThrow([&validSource] {
    const ShaderObject shaderObject({
      &validSource,
    });
  });
}

TEST_F(ShaderObjectTest, invalidSourceCount) {
  EXPECT_THROW(
    const ShaderObject shaderObject({}),
    runtime_error
  );
}

TEST_F(ShaderObjectTest, differentSourceTypes) {
  const ShaderSource invalidSources[] {
    { testShaderPath("valid.vert") },
    { testShaderPath("valid.frag") },
  };

  EXPECT_THROW(
    const ShaderObject shaderObject({
      &invalidSources[0],
      &invalidSources[1],
    }),

    runtime_error
  );
}

TEST_F(ShaderObjectTest, compilationFailure) {
  const ShaderSource invalidSources[] {
    { testShaderPath("valid.vert")   },
    { testShaderPath("invalid.vert") },
  };

  EXPECT_THROW(
    const ShaderObject shaderObject({
      &invalidSources[0],
      &invalidSources[1],
    }),

    runtime_error
  );
}
