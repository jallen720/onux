#include "ShaderProgram.hpp"

#include <stdexcept>

#include "fixtures/ShaderProgramTest.hpp"
#include "glHelpers.hpp"

using std::runtime_error;

TEST_F(ShaderProgramTest, validCreation) {
  expectNoThrow([&] {
    ShaderProgram({
      &validObjects[0],
      &validObjects[1],
    });
  });
}

TEST_F(ShaderProgramTest, notAllRequiredTypes) {
  // A ShaderProgram requires atleast a vertex shader object and a fragment
  // shader object.
  EXPECT_THROW(
    ShaderProgram({
      &validObjects[0],
    }),
    runtime_error
  );
}

TEST_F(ShaderProgramTest, missingMainFunctionInObject) {
  const ShaderSource noMainSource(testShaderPath("noMain.vert"));
  const ShaderObject noMainObject({ &noMainSource });

  EXPECT_THROW(
    ShaderProgram({
      &noMainObject,
      &validObjects[1],
    }),
    runtime_error
  );
}

TEST_F(ShaderProgramTest, use) {
  const ShaderProgram shaderProgram({
    &validObjects[0],
    &validObjects[1],
  });

  // Only after calling use() should a ShaderProgram be the current program.
  ASSERT_NE(getInt(GL_CURRENT_PROGRAM), shaderProgram.getID());

  shaderProgram.use();
  EXPECT_EQ(getInt(GL_CURRENT_PROGRAM), shaderProgram.getID());
}
