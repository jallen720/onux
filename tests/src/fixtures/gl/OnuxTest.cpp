#include "fixtures/gl/OnuxTest.hpp"

#include <iostream>

#include "environment/loadExtensions.hpp"
#include "gl/utils/validateNoGLError.hpp"
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
    validateNoUnhandledGLError();
}
