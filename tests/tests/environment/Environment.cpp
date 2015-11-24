#include "environment/Environment.hpp"

#include "fixtures/EnvironmentTest.hpp"
#include "testHelpers.hpp"

using onux::Environment;

TEST_F(EnvironmentTest, validCreation) {
  expectNoThrow([] {
    const Environment environment;
  });
}
