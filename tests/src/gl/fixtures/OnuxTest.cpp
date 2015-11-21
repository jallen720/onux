#include "OnuxTest.hpp"

#include <iostream>

#include "environment/extensions.hpp"
#include "exceptions/subsystemErrors/OpenGlError.hpp"

using std::cerr;
using onux::loadExtensions;
using onux::OpenGlError;

static void validateNoOpenGlError(const GLenum error) {
  // Validate no error was generated during test. This is required for all tests that use OpenGL
  // functions.
  if (error != GL_NO_ERROR) {
    throw OpenGlError(error);
  }
}

static void checkUnhandledOpenGlError() {
  try {
    validateNoOpenGlError(glGetError());
  } catch(const OpenGlError& e) {
    cerr <<
      "Unhandled OpenGL error generated in test:\n"
      "  " << e.what() << "\n\n";

    FAIL();
  }
}

OnuxTest::OnuxTest() {
  window.makeContextCurrent();
  loadExtensions();
}

OnuxTest::~OnuxTest() {
  checkUnhandledOpenGlError();
}
