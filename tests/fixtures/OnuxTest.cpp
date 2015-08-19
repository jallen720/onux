#include "OnuxTest.hpp"

#include <iostream>

#include "extensions.hpp"
#include "onux_gl/helpers.hpp"

using std::cerr;
using onux_gl::getErrorMsg;

static void checkUnhandledGLError() {
  const GLenum error = glGetError();

  // Validate no error was generated during test. This
  // is required for all tests that use OpenGL functions.
  if (error != GL_NO_ERROR) {
    cerr << "Unhandled OpenGL error generated:\n"
         << "  " << getErrorMsg(error) << "\n\n";

    FAIL();
  }
}

OnuxTest::OnuxTest()
  : window(1280, 720, "OnuxTest") {
  loadExtensions();
}

OnuxTest::~OnuxTest() {
  checkUnhandledGLError();
}
