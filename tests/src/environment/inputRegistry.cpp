#include "environment/inputRegistry.hpp"

#include <GL/glew.h> // Required before other OpenGL headers
#include <GLFW/glfw3.h>

#include "tests/fixtures/environment/inputRegistryTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using onux::registerInput;
using onux::unregisterInput;
using onux::NullArg;

TEST_F(inputRegistryTest, validRegistry) {
    expectNoThrow([&] {
        registerInput(&input, window);
    });
}

TEST_F(inputRegistryTest, registerNullInput) {
    EXPECT_THROW(registerInput(nullptr, window), NullArg);
}

TEST_F(inputRegistryTest, registerNullWindow) {
    EXPECT_THROW(registerInput(&input, nullptr), NullArg);
}

TEST_F(inputRegistryTest, validUnregistry) {
    registerInput(&input, window);

    expectNoThrow([&] {
        unregisterInput(window);
    });
}

TEST_F(inputRegistryTest, unregisterNullWindow) {
    EXPECT_THROW(unregisterInput(nullptr), NullArg);
}
