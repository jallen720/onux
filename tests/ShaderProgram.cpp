#include "ShaderProgram.hpp"

#include <stdexcept>
#include <glm/glm.hpp>

#include "fixtures/ShaderProgramTest.hpp"
#include "glHelpers.hpp"

using std::runtime_error;
using glm::vec4;

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

TEST_F(ShaderProgramTest, setUniform) {
  const ShaderProgram shaderProgram({
    &validObjects[0],
    &validObjects[1],
  });

  // A ShaderProgram must be the current program in order to set uniforms.
  shaderProgram.use();

  expectNoThrow([&shaderProgram] {
    shaderProgram.setUniform("testPosition", vec4(-1.f, -0.5f, 0.f, 1.f));
    shaderProgram.setUniform("testColor", vec4(1.f, 0.5f, 0.f, 1.f));
  });
}

TEST_F(ShaderProgramTest, setUniformUnusedUniform) {
  const ShaderSource unusedUniformSource(testShaderPath("unusedUniform.vert"));
  const ShaderObject unusedUniformObject({ &unusedUniformSource });

  const ShaderProgram shaderProgram({
    &unusedUniformObject,
    &validObjects[1],
  });

  // OpenGL optimizes out unused uniforms, so trying to set a uniform that is
  // unused will fail, as the uniform won't exist.
  EXPECT_THROW(
    shaderProgram.setUniform("unusedPosition", vec4(-1.f, -0.5f, 0.f, 1.f)),
    runtime_error
  );
}

TEST_F(ShaderProgramTest, setUniformNotCurrentProgram) {
  const ShaderProgram shaderProgram({
    &validObjects[0],
    &validObjects[1],
  });

  // Trying to set a uniform on a program that is not the current program will
  // generate a GL_INVALID_OPERATION error.
  expectGLError(GL_INVALID_OPERATION, [&shaderProgram] {
    shaderProgram.setUniform("testPosition", vec4(-1.f, -0.5f, 0.f, 1.f));
  });
}
