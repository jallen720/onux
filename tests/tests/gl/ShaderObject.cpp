#include "gl/ShaderObject.hpp"

#include "fixtures/ShaderObjectTest.hpp"
#include "utils/expectNoThrow.hpp"
#include "utils/testShaderPath.hpp"
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
  const ShaderSource validSource(testShaderPath("valid.vert"));

  expectNoThrow([&validSource] {
    const ShaderObject shaderObject({
      &validSource,
    });
  });
}

TEST_F(ShaderObjectTest, noSources) {
  EXPECT_THROW(
    const ShaderObject shaderObject({}),
    InvalidArgProperty
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

    ArgFailedRequirement
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

    Error
  );
}
