#include "testHelpers.hpp"

#include <iostream>
#include <exception>
#include <gtest/gtest.h>
#include <Magick++.h>

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

void magickErrorFinder(const function<void()>& block) {
  using namespace Magick;

  try {
    block();
    cerr << "No Magick++ error thrown" << endl;
  } catch (const ErrorUndefined& e) {
    cerr << "ErrorUndefined thrown: " << e.what() << endl;
  } catch (const ErrorBlob& e) {
    cerr << "ErrorBlob thrown: " << e.what() << endl;
  } catch (const ErrorCache& e) {
    cerr << "ErrorCache thrown: " << e.what() << endl;
  } catch (const ErrorCoder& e) {
    cerr << "ErrorCoder thrown: " << e.what() << endl;
  } catch (const ErrorConfigure& e) {
    cerr << "ErrorConfigure thrown: " << e.what() << endl;
  } catch (const ErrorCorruptImage& e) {
    cerr << "ErrorCorruptImage thrown: " << e.what() << endl;
  } catch (const ErrorDelegate& e) {
    cerr << "ErrorDelegate thrown: " << e.what() << endl;
  } catch (const ErrorDraw& e) {
    cerr << "ErrorDraw thrown: " << e.what() << endl;
  } catch (const ErrorFileOpen& e) {
    cerr << "ErrorFileOpen thrown: " << e.what() << endl;
  } catch (const ErrorImage& e) {
    cerr << "ErrorImage thrown: " << e.what() << endl;
  } catch (const ErrorMissingDelegate& e) {
    cerr << "ErrorMissingDelegate thrown: " << e.what() << endl;
  } catch (const ErrorModule& e) {
    cerr << "ErrorModule thrown: " << e.what() << endl;
  } catch (const ErrorMonitor& e) {
    cerr << "ErrorMonitor thrown: " << e.what() << endl;
  } catch (const ErrorOption& e) {
    cerr << "ErrorOption thrown: " << e.what() << endl;
  } catch (const ErrorRegistry& e) {
    cerr << "ErrorRegistry thrown: " << e.what() << endl;
  } catch (const ErrorResourceLimit& e) {
    cerr << "ErrorResourceLimit thrown: " << e.what() << endl;
  } catch (const ErrorStream& e) {
    cerr << "ErrorStream thrown: " << e.what() << endl;
  } catch (const ErrorType& e) {
    cerr << "ErrorType thrown: " << e.what() << endl;
  } catch (const ErrorXServer& e) {
    cerr << "ErrorXServer thrown: " << e.what() << endl;
  } catch(...) {
    cerr << "Unknown error thrown" << endl;
  }
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
