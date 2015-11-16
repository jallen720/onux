#include "graphics/Mesh.hpp"

#include "fixtures/MeshTest.hpp"
#include "exceptions/NullArg.hpp"

using onux::Mesh;
using onux::NullArg;

TEST_F(MeshTest, validCreation) {
  expectNoThrow([&] {
    const Mesh mesh(cubeMesh);
  });
}

TEST_F(MeshTest, invalidMesh) {
  EXPECT_THROW(
    const Mesh mesh(nullptr),
    NullArg
  );
}

TEST_F(MeshTest, validData) {
  const auto INDEXES_PER_FACE = 3u;
  const Mesh mesh(cubeMesh);

  ASSERT_EQ(
    cubeMesh->mNumVertices,
    mesh.getVertexes().getCount()
  );

  ASSERT_EQ(
    cubeMesh->mNumFaces * INDEXES_PER_FACE,
    mesh.getIndexes().getCount()
  );
}
