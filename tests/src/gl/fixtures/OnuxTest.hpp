#pragma once

#include <GL/glew.h> // Must include before any OpenGL headers.

#include <gtest/gtest.h>

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
