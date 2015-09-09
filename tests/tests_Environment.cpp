#include "Environment.hpp"

#include "fixtures/EnvironmentTest.hpp"
#include "test_util.hpp"

TEST_F(EnvironmentTest, validCreation) {
  expectNoThrow([] {
    const Environment environment;
  });
}
