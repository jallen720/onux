#pragma once

#include <GL/glew.h> // Must include before any OpenGL headers.

#include <gtest/gtest.h>

#include "Environment.hpp"
#include "Window.hpp"

struct OnuxTest : testing::Test {
private:
  const Environment environment;
  const Window window { 1280, 720, "OnuxTest" };

protected:
  OnuxTest();
  ~OnuxTest();
};
