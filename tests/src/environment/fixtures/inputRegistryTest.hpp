#pragma once

#include <gtest/gtest.h>

#include "environment/Environment.hpp"
#include "environment/Input.hpp"

struct GLFWwindow;

struct inputRegistryTest : testing::Test {
protected:
  const onux::Environment environment;
  GLFWwindow* window;
  onux::Input input;

  inputRegistryTest();
  ~inputRegistryTest();
};
