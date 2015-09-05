#include "test_util.hpp"

#include <iostream>
#include <exception>
#include <gtest/gtest.h>

using std::cerr;
using std::endl;
using std::exception;

static const string TEST_SHADERS_DIRECTORY = "tests/resources/shaders/";
static const string TEST_IMAGES_DIRECTORY = "tests/resources/images/";
static const string TEST_MODELS_DIRECTORY = "tests/resources/models/";

const string testShaderPath(const string& name) {
  return TEST_SHADERS_DIRECTORY + name;
}

const string testImagePath(const string& name) {
  return TEST_IMAGES_DIRECTORY + name;
}

const string testModelPath(const string& name) {
  return TEST_MODELS_DIRECTORY + name;
}

void expectNoThrow(const function<void()>& block) {
  try {
    block();
  } catch (const exception& e) {
    cerr << "Exception throw in test:\n  " << e.what() << endl;
    FAIL();
  } catch(...) {
    cerr << "Unknown exception thrown in test!\n";
    FAIL();
  }
}

void expectGLError(const GLenum error, const function<void()>& block) {

  // Assert no error has already been generated before
  // testing block error generation.
  ASSERT_EQ(GL_NO_ERROR, glGetError());

  // Run block where error is expected to be generated.
  block();

  // Expect error was generated during block.
  EXPECT_EQ(error, glGetError());
}

/*

#include "GLData.hpp"
#include "GLUtil.hpp"

void assertGLError(const GLenum error, const function<void()>& block) {

  // Assert no error has already been generated before
  // testing block error generation.
  ASSERT_EQ(GL_NO_ERROR, glGetError());

  // Run block where error is expected to be generated.
  block();

  // Expect error was generated during block.
  ASSERT_EQ(error, glGetError());
}

void expectNoGLError(const function<void()>& block) {
  expectGLError(GL_NO_ERROR, block);
}

void assertNoGLError(const function<void()>& block) {
  assertGLError(GL_NO_ERROR, block);
}

void existsTest(const GLData& glData) {

  // GLDatas do not exist before they have been associated
  // with an OpenGL object through calling glBind*().
  ASSERT_FALSE(glData.exists());

  glData.bind();

  // GLDatas exist only after they have been associated
  // with an OpenGL object through calling glBind*().
  ASSERT_TRUE(glData.exists());

  glData.release();

  // GLDatas continue to exist after they have been
  // associated with an OpenGL object through calling glBind*()
  // even if they are not currently bound to that object.
  ASSERT_TRUE(glData.exists());

  glData.destroy();

  // GLDatas no longer exist after they have been destroyed.
  EXPECT_FALSE(glData.exists());
}

void existsTest(const GLObject& glObject) {

  // GLObjects should exists after successful construction.
  ASSERT_TRUE(glObject.exists());

  glObject.destroy();

  // GLObjects should not exist after they are destroyed.
  EXPECT_FALSE(glObject.exists());
}

void destroyTest(const GLData& glData) {
  // TODO: Check that a bound GLData that is deleted
  // reverts the binding for it's target to 0.

  // GLDatas do not exist before they have been associated
  // with an OpenGL object through calling glBind*().
  ASSERT_FALSE(glData.exists());

  glData.bind();

  // GLDatas exist only after they have been associated
  // with an OpenGL object through calling glBind*().
  ASSERT_TRUE(glData.exists());

  // Destroying a GLData that exists and is bound shouldn't
  // generate any errors.
  assertNoGLError([&] {
    glData.destroy();
  });

  // GLDatas no longer exist after they have been destroyed.
  ASSERT_FALSE(glData.exists());

  // Destroying a GLData after it has already been destroyed
  // (and therefore no longer associated with an OpenGL object) is
  // silently ignored and should not generate any errors.
  expectNoGLError([&] {
    glData.destroy();
  });
}

void destroyTest(const GLObject& glObject) {

  // GLObjects should exists after successful construction.
  ASSERT_TRUE(glObject.exists());

  // Destroying a GLObject that exists shouldn't generate
  // an error.
  assertNoGLError([&] {
    glObject.destroy();
  });

  // GLObjects should not exist after they are destroyed.
  ASSERT_FALSE(glObject.exists());

  // Attempting to destroy a GLObject that doesn't exist
  // shouldn't generate an error as GLObjects ensure they
  // exist before calling glDelete*().
  assertNoGLError([&] {
    glObject.destroy();
  });

  // Deleting a GLObject that doesn't exist should generate
  // an error.
  expectGLError(GL_INVALID_VALUE, [&] {
    glDeleteProgram(glObject.getID());
  });
}

void destroyResetsTargetTest(const GLData& glData, const GLenum targetBinding) {

  // glData must pass bindTest as a prerequisite.
  bindTest(glData, targetBinding);

  glData.destroy();

  // Nothing should be bound to targetBinding
  EXPECT_EQ(0, getInt(targetBinding));
}

void bindTest(const GLData& glData, const GLenum targetBinding) {

  // Nothing should be bound to targetBinding
  ASSERT_EQ(0, getInt(targetBinding));

  glData.bind();

  // glData should be bound to targetBinding
  ASSERT_EQ(glData.getID(), getInt(targetBinding));
}

void releaseTest(const GLData& glData, const GLenum targetBinding) {

  // glData must pass bindTest before it can pass releaseTest.
  bindTest(glData, targetBinding);

  glData.release();

  // Nothing should be bound to targetBinding
  EXPECT_EQ(0, getInt(targetBinding));
}

void getIDTest(
  const GLint id1, const GLObject& glObject1,
  const GLint id2, const GLObject& glObject2
) {

  // Test that 2 consecutively created GLObjects have
  // 2 consecutive OpenGL generated ids.
  ASSERT_EQ(id1, glObject1.getID());
  EXPECT_EQ(id2, glObject2.getID());
}

void getIDTest(const GLObject& glObject1, const GLObject& glObject2) {

  // The first ID generated by OpenGL is 1, and all other IDs are the
  // next consecutive integer after the previously generated ID.
  static const GLint FRST_GL_ID = 1;
  static const GLint SCND_GL_ID = FRST_GL_ID + 1;

  // Test that 2 consecutively created GLObjects have
  // the first 2 consecutive OpenGL generated ids.
  getIDTest(
    FRST_GL_ID, glObject1,
    SCND_GL_ID, glObject2
  );
}
*/
