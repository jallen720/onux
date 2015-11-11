#include "graphics/Scene.hpp"

#include <stdexcept>

#include "fixtures/SceneTest.hpp"
#include "testHelpers.hpp"

using std::runtime_error;
using onux::Scene;

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

TEST_F(SceneTest, invalidPath) {
  EXPECT_THROW(
    const Scene scene(""),
    runtime_error
  );
}
