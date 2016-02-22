#include "graphics/Mesh.hpp"

#include "tests/fixtures/graphics/MeshTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using onux::Mesh;
using onux::NullArg;

TEST_F(MeshTest, validCreation) {
    expectNoThrow([&] {
        Mesh { cubeMesh };
    });
}

TEST_F(MeshTest, invalidMesh) {
    EXPECT_THROW(Mesh(nullptr), NullArg);
}

TEST_F(MeshTest, validData) {
    static const auto INDEXES_PER_FACE = 3u;
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
