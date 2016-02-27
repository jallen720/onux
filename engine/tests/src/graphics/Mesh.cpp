#include "graphics/Mesh.hpp"

#include <assimp/mesh.h>

#include "tests/fixtures/graphics/MeshTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using onux::Mesh;
using onux::NullArg;

TEST_F(MeshTest, validCreation) {
    expectNoThrow([&] {
        Mesh::create(cubeAssimpMesh);
    });
}

TEST_F(MeshTest, invalidMesh) {
    EXPECT_THROW(Mesh::create(nullptr), NullArg);
}

TEST_F(MeshTest, validData) {
    static const auto INDEXES_PER_FACE = 3u;

    const Mesh::Ptr mesh = Mesh::create(cubeAssimpMesh);

    ASSERT_EQ(
        cubeAssimpMesh->mNumVertices,
        mesh->getVertexes().getCount()
    );

    ASSERT_EQ(
        cubeAssimpMesh->mNumFaces * INDEXES_PER_FACE,
        mesh->getIndexes().getCount()
    );
}
