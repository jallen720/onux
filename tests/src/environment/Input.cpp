#include "environment/Input.hpp"

#include <gtest/gtest.h>
#include <glm/glm.hpp>

#include "tests/TestWindow.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "environment/interfaces/IMouseMoveListener.hpp"
#include "environment/events/MouseMoveEvent.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using glm::dvec2;
using onux::Input;
using onux::IMouseMoveListener;
using onux::NullArg;

TEST(InputTest, validCreation) {
    expectNoThrow([&] {
        Input(TestWindow());
    });
}

TEST(InputTest, invalidWindow) {
    EXPECT_THROW(Input(nullptr), NullArg);
}

TEST(InputTest, cursorPosEvent) {
    static const dvec2 expected(1.0, 2.0);

    TestWindow window;
    Input input(window);

    struct MouseMoveListener : IMouseMoveListener {
        void onMouseMove(const dvec2& position) override {
            ASSERT_EQ(expected.x, position.x);
            ASSERT_EQ(expected.y, position.y);
        }
    } mouseMoveListener;

    input.getMouseMoveEvent().add(&mouseMoveListener);
    input.cursorPosEvent(expected.x, expected.y);
    input.getMouseMoveEvent().remove(&mouseMoveListener);
}
