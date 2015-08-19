#include "onux_gl/ShaderObject.hpp"

#include <stdexcept>

#include "fixtures/ShaderObjectTest.hpp"
#include "testUtil.hpp"
#include "ShaderSource.hpp"

using std::runtime_error;

TEST_F(ShaderObjectTest, validCreation) {
  const ShaderSource source(testShaderPath("valid.vert"));

  expectNoThrow([&source] {
    ShaderObject({ &source });
  });
}

TEST_F(ShaderObjectTest, invalidSourceCount) {
  EXPECT_THROW(
    ShaderObject({}),
    runtime_error
  );
}

TEST_F(ShaderObjectTest, differentSourceTypes) {
  const ShaderSource sources[] {
    { testShaderPath("valid.vert") },
    { testShaderPath("valid.frag") },
  };

  EXPECT_THROW(
    ShaderObject({ &sources[0], &sources[1] }),
    runtime_error
  );
}

TEST_F(ShaderObjectTest, compilationFailure) {
  const ShaderSource sources[] {
    { testShaderPath("valid.vert")   },
    { testShaderPath("invalid.vert") },
  };

  EXPECT_THROW(
    ShaderObject({ &sources[0], &sources[1] }),
    runtime_error
  );
}
