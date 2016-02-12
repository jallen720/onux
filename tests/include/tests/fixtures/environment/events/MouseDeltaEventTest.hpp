#pragma once

#include <gtest/gtest.h>

#include "environment/events/MouseDeltaEvent.hpp"

class MouseDeltaEventTest : public testing::Test {
protected:
    onux::MouseDeltaEvent mouseDeltaEvent;
};
