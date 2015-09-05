#include "Mesh.hpp"

#include "fixtures/MeshTest.hpp"

TEST_F(MeshTest, validCreation) {
  expectNoThrow([&] {
    const Mesh mesh(cubeMesh);
  });
}

TEST_F(MeshTest, validData) {
  const Mesh mesh(cubeMesh);

  // Cube mesh should have 24 vertexes & 36 indexes.
  ASSERT_EQ(24, mesh.getVertexes().size());
  ASSERT_EQ(36, mesh.getIndexes().size());
}
