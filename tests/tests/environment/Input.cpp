#include "environment/Input.hpp"

#include <gtest/gtest.h>
#include <glm/glm.hpp>

#include "TestWindow.hpp"
#include "utils/expectNoThrow.hpp"
#include "environment/interfaces/IMouseMoveListener.hpp"
#include "environment/events/MouseMoveEvent.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using glm::dvec2;
using onux::Input;
using onux::IMouseMoveListener;
using onux::NullArg;

TEST(InputTest, validCreation) {
  expectNoThrow([&] {
    const Input input { TestWindow() };
  });
}

TEST(InputTest, invalidWindow) {
  EXPECT_THROW(
    const Input input(nullptr),
    NullArg
  );
}

TEST(InputTest, cursorPosEventWorks) {
  static const struct {
    const double X = 1.0;
    const double Y = 2.0;
  } VALID;

  TestWindow window;
  Input input(window);

  struct MouseMoveListener : IMouseMoveListener {
    void onMouseMove(const dvec2& position) override {
      ASSERT_EQ(VALID.X, position.x);
      ASSERT_EQ(VALID.Y, position.y);
    }
  } mouseMoveListener;

  input.getMouseMoveEvent().add(&mouseMoveListener);
  input.cursorPosEvent(VALID.X, VALID.Y);
}
