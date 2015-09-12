#pragma once

#include <gtest/gtest.h>

#include "Environment.hpp"

struct WindowTest : testing::Test {
protected:
  onux::Environment environment;
};
