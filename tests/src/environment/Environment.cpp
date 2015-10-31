#include "environment/Environment.hpp"

#include "fixtures/EnvironmentTest.hpp"
#include "testUtil.hpp"

using onux::Environment;

TEST_F(EnvironmentTest, validCreation) {
  expectNoThrow([] {
    const Environment environment;
  });
}
