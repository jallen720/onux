#include "graphics/Scene.hpp"

#include "fixtures/SceneTest.hpp"
#include "testUtil.hpp"

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
