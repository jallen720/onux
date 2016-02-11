#include "environment/Environment.hpp"

#include "fixtures/environment/EnvironmentTest.hpp"
#include "utils/expectNoThrow.hpp"

using onux::Environment;

TEST_F(EnvironmentTest, validCreation) {
    expectNoThrow([] {
        Environment();
    });
}
