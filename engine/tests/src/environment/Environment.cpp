#include "environment/Environment.hpp"

#include "tests/fixtures/environment/EnvironmentTest.hpp"
#include "tests/utils/expectNoThrow.hpp"

using onux::Environment;

TEST_F(EnvironmentTest, validCreation) {
    expectNoThrow([] {
        Environment();
    });
}
