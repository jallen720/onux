#include "tests/fixtures/environment/events/EventTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using onux::NullArg;

TEST_F(EventTest, addValidListener) {
    MockListener mockListener;

    expectNoThrow([&] {
        mockEvent.addListener(&mockListener);
    });
}

TEST_F(EventTest, removeValidListener) {
    MockListener mockListener;
    mockEvent.addListener(&mockListener);

    expectNoThrow([&] {
        mockEvent.removeListener(&mockListener);
    });
}

TEST_F(EventTest, addNullListener) {
    EXPECT_THROW(mockEvent.addListener(nullptr), NullArg);
}

TEST_F(EventTest, removeNullListener) {
    EXPECT_THROW(mockEvent.removeListener(nullptr), NullArg);
}
