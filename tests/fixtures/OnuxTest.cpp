#include "OnuxTest.hpp"

#include <iostream>

#include "extensions.hpp"
#include "glHelpers.hpp"

using std::cerr;

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
