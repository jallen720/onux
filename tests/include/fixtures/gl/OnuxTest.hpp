#pragma once

#include <gtest/gtest.h>
#include <GL/glew.h> // Required before other OpenGL headers

#include "environment/Environment.hpp"
#include "environment/Window.hpp"

struct OnuxTest : testing::Test {
private:
    const onux::Environment environment;
    const onux::Window window { 1280, 720, "OnuxTest" };

protected:
    OnuxTest();
    ~OnuxTest();
};
