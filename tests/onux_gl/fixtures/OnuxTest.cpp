#include "OnuxTest.hpp"

#include <iostream>

#include "extensions.hpp"
#include "onux_gl/helpers.hpp"

using std::cerr;
using onux_gl::getErrorMsg;

static void printUnhandledGLError(const GLenum error) {
    cerr << "Unhandled OpenGL error generated:\n"
         << "  " << getErrorMsg(error) << "\n\n";
}

static void validateNoGLError(const GLenum error) {
  // Validate no error was generated during test. This is required for all tests
  // that use OpenGL functions.
  if (error != GL_NO_ERROR) {
    printUnhandledGLError(error);
    FAIL();
  }
}

OnuxTest::OnuxTest() {
  loadExtensions();
}

OnuxTest::~OnuxTest() {
  validateNoGLError(glGetError());
}
