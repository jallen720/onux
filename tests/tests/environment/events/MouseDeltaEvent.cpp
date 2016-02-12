#include "environment/events/MouseDeltaEvent.hpp"

#include <vector>
#include <glm/glm.hpp>

#include "fixtures/environment/events/MouseDeltaEventTest.hpp"
#include "environment/interfaces/IMouseDeltaListener.hpp"

using std::vector;
using glm::dvec2;

using onux::MouseDeltaEvent;
using onux::IMouseDeltaListener;

TEST_F(MouseDeltaEventTest, trigger) {
    struct MouseDeltaListener : IMouseDeltaListener {
        dvec2 currentDelta;

        // IMouseDeltaListener
        virtual void onMouseDelta(const dvec2& delta) override {
            currentDelta = delta;
        }
    } mouseDeltaListener;

    mouseDeltaEvent.add(&mouseDeltaListener);

    // The first time the mouseDeltaEvent is triggered, it will initialize the previous mouse
    // position to the current mouse position, which will always result in a delta of (0, 0).
    mouseDeltaEvent.trigger(dvec2(1, 2));
    ASSERT_EQ(mouseDeltaListener.currentDelta.x, 0);
    ASSERT_EQ(mouseDeltaListener.currentDelta.y, 0);

    mouseDeltaEvent.trigger(dvec2(3, 5));
    ASSERT_EQ(mouseDeltaListener.currentDelta.x, 2);
    ASSERT_EQ(mouseDeltaListener.currentDelta.y, 3);

    mouseDeltaEvent.trigger(dvec2(-2, 0));
    ASSERT_EQ(mouseDeltaListener.currentDelta.x, -5);
    ASSERT_EQ(mouseDeltaListener.currentDelta.y, -5);

    mouseDeltaEvent.remove(&mouseDeltaListener);
}
