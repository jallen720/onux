#include "graphics/Scene.hpp"

#include "fixtures/SceneTest.hpp"
#include "testHelpers.hpp"
#include "exceptions/AssimpError.hpp"
#include "exceptions/EmptyStringArg.hpp"

using onux::Scene;
using onux::AssimpError;
using onux::EmptyStringArg;

TEST_F(SceneTest, validCreation) {
  expectNoThrow([] {
    const Scene scene(testModelPath("cube.obj"));
  });
}

TEST_F(SceneTest, validData) {
  const Scene scene(testModelPath("cube.obj"));

  // Cube scene should have 1 mesh
  ASSERT_EQ(1, scene.getMeshes().size());
}

TEST_F(SceneTest, emptyPath) {
  EXPECT_THROW(
    const Scene scene(""),
    EmptyStringArg
  );
}

TEST_F(SceneTest, invalidPath) {
  EXPECT_THROW(
    const Scene scene("invalid/path"),
    AssimpError
  );
}
