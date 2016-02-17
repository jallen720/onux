#include "tests/fixtures/gl/OnuxTest.hpp"

#include <iostream>

#include "gl/utils/loadExtensions.hpp"
#include "exceptions/validators/validateNoGLError.hpp"
#include "exceptions/subsystemErrors/GLError.hpp"

using std::cerr;
using onux::loadExtensions;
using onux::validateNoGLError;
using onux::GLError;

static void validateNoUnhandledGLError() {
    try {
        validateNoGLError();
    }
    catch(const GLError& e) {
        cerr << "Unhandled OpenGL error generated in test: " << e.what() << "\n";
        FAIL();
    }
}

OnuxTest::OnuxTest() {
    window.makeContextCurrent();
    loadExtensions();
}

OnuxTest::~OnuxTest() {
    validateNoUnhandledGLError();
}
