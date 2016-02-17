#pragma once

#include <gtest/gtest.h>

#include "environment/events/Event.hpp"

class EventTest : public testing::Test {
protected:
    class MockListener {};

    class MockEvent : public onux::Event<MockListener> {
    public:
        virtual void trigger() override {}
    } mockEvent;
};
