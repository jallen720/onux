#pragma once

#include <gtest/gtest.h>

#include "environment/events/MouseMoveEvent.hpp"

class MouseMoveEventTest : public testing::Test {
protected:
    onux::MouseMoveEvent mouseMoveEvent;
};
