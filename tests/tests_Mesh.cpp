#include "Mesh.hpp"

#include "fixtures/MeshTest.hpp"

using onux::Mesh;

TEST_F(MeshTest, validCreation) {
  expectNoThrow([&] {
    const Mesh mesh(cubeMesh);
  });
}

TEST_F(MeshTest, validData) {
  const auto INDEXES_PER_FACE = 3u;
  const Mesh mesh(cubeMesh);

  ASSERT_EQ(
    cubeMesh->mNumVertices,
    mesh.getVertexes().size()
  );

  ASSERT_EQ(
    cubeMesh->mNumFaces * INDEXES_PER_FACE,
    mesh.getIndexes().size()
  );
}
