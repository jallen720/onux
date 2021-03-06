#pragma once

#include <gtest/gtest.h>

#include "tests/TestWindow.hpp"
#include "environment/Input.hpp"

struct inputRegistryTest : testing::Test {
protected:
    TestWindow window;
    onux::Input input { window };
};
