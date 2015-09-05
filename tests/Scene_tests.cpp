#include "Scene.hpp"

#include "fixtures/SceneTest.hpp"
#include "test_util.hpp"

TEST_F(SceneTest, validCreation) {
  expectNoThrow([&] {
    const Scene scene(testModelPath("cube.obj"));
  });
}

TEST_F(SceneTest, validData) {
  const Scene scene(testModelPath("cube.obj"));

  // Cube scene should have 1 mesh
  ASSERT_EQ(1, scene.getMeshes().size());

  const Mesh& mesh = scene.getMeshes()[0];

  // Cube mesh should have 24 vertexes & 36 indexes.
  ASSERT_EQ(24, mesh.getVertexes().size());
  ASSERT_EQ(36, mesh.getIndexes().size());
}
