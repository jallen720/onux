#include "test_util.hpp"

#include <iostream>
#include <exception>
#include <gtest/gtest.h>

using std::cerr;
using std::endl;
using std::exception;
using std::string;
using std::function;

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

  // Assert no error has already been generated before testing block error
  // generation.
  ASSERT_EQ(GL_NO_ERROR, glGetError());

  // Run block where error is expected to be generated.
  block();

  // Expect error was generated during block.
  EXPECT_EQ(error, glGetError());
}

/*
void assertGLError(const GLenum error, const function<void()>& block) {

  // Assert no error has already been generated before
  // testing block error generation.
  ASSERT_EQ(GL_NO_ERROR, glGetError());

  // Run block where error is expected to be generated.
  block();

  // Expect error was generated during block.
  ASSERT_EQ(error, glGetError());
}

void bindTest(const GLData& glData, const GLenum targetBinding) {

  // Nothing should be bound to targetBinding
  ASSERT_EQ(0, getInt(targetBinding));

  glData.bind();

  // glData should be bound to targetBinding
  ASSERT_EQ(glData.getID(), getInt(targetBinding));
}
*/
