#include <GL/glew.h> // Required before other OpenGL headers

#include "environment/Window.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"
#include "exceptions/argErrors/NullArg.hpp"
#include "fixtures/environment/WindowTest.hpp"
#include "utils/expectNoThrow.hpp"

using onux::Window;
using onux::InvalidArg;
using onux::EmptyStringArg;
using onux::NullArg;

TEST_F(WindowTest, validCreation) {
    expectNoThrow([] {
        Window(1280, 720, "Test Window");
    });
}

TEST_F(WindowTest, invalidName) {
    EXPECT_THROW(Window(1280, 720, nullptr), NullArg);
    EXPECT_THROW(Window(1280, 720, ""), EmptyStringArg);
}

TEST_F(WindowTest, invalidDimensions) {
    EXPECT_THROW(Window(1280, 0  , "Test Window"), InvalidArg);
    EXPECT_THROW(Window(0   , 720, "Test Window"), InvalidArg);
    EXPECT_THROW(Window(0   , 0  , "Test Window"), InvalidArg);
}

TEST_F(WindowTest, aspect) {
    EXPECT_EQ((float)1280 / 720, Window(1280, 720, "Test Window").getAspect());
}
