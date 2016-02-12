#include "tests/fixtures/environment/events/EventTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using onux::NullArg;

TEST_F(EventTest, addValidListener) {
    MockListener mockListener;

    expectNoThrow([&] {
        mockEvent.add(&mockListener);
    });
}

TEST_F(EventTest, removeValidListener) {
    MockListener mockListener;
    mockEvent.add(&mockListener);

    expectNoThrow([&] {
        mockEvent.remove(&mockListener);
    });
}

TEST_F(EventTest, addNullListener) {
    EXPECT_THROW(mockEvent.add(nullptr), NullArg);
}

TEST_F(EventTest, removeNullListener) {
    EXPECT_THROW(mockEvent.remove(nullptr), NullArg);
}
