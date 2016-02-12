#include "environment/events/MouseMoveEvent.hpp"

#include <vector>
#include <glm/glm.hpp>

#include "fixtures/environment/events/MouseMoveEventTest.hpp"
#include "environment/interfaces/IMouseMoveListener.hpp"

using std::vector;
using glm::dvec2;

using onux::MouseMoveEvent;
using onux::IMouseMoveListener;

TEST_F(MouseMoveEventTest, trigger) {
    static const dvec2 expected(2.0, 3.0);

    struct MouseMoveListener : IMouseMoveListener {
        void onMouseMove(const dvec2& position) override {
            ASSERT_EQ(expected.x, position.x);
            ASSERT_EQ(expected.y, position.y);
        }
    } mouseMoveListener;

    mouseMoveEvent.add(&mouseMoveListener);
    mouseMoveEvent.trigger(dvec2(expected.x, expected.y));
    mouseMoveEvent.remove(&mouseMoveListener);
}
