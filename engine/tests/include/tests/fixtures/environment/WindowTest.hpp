#pragma once

#include <gtest/gtest.h>

#include "environment/Environment.hpp"

struct WindowTest : testing::Test {
protected:
    onux::Environment environment;
};
