#pragma once

#include <GL/glew.h> // Must include before all other OpenGL headers.
#include <gtest/gtest.h>

#include "Window.hpp"

using testing::Test;

class OnuxTest : public Test {
  const Window window;

public:
  OnuxTest();
  ~OnuxTest();
};
