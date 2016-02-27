#include "graphics/Mesh.hpp"

#include <assimp/mesh.h>

#include "tests/fixtures/graphics/MeshTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using onux::Mesh;
using onux::NullArg;

TEST_F(MeshTest, validCreation) {
    expectNoThrow([&] {
        Mesh::create(cubeMesh);
    });
}

TEST_F(MeshTest, invalidMesh) {
    EXPECT_THROW(Mesh::create(nullptr), NullArg);
}

TEST_F(MeshTest, validData) {
    static const auto INDEXES_PER_FACE = 3u;
    const Mesh::Ptr mesh = Mesh::create(cubeMesh);

    ASSERT_EQ(
        cubeMesh->mNumVertices,
        mesh->getVertexes().getCount()
    );

    ASSERT_EQ(
        cubeMesh->mNumFaces * INDEXES_PER_FACE,
        mesh->getIndexes().getCount()
    );
}
