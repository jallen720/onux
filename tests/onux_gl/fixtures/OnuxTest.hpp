#pragma once

#include <GL/glew.h> // Must include before any OpenGL headers.

#include <gtest/gtest.h>

#include "Environment.hpp"
#include "Window.hpp"

using testing::Test;

class OnuxTest : public Test {
  const Environment environment;
  const Window window { 1280, 720, "OnuxTest" };

public:
  OnuxTest();
  ~OnuxTest();
};
