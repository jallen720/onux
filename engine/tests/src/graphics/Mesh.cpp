#include "graphics/Mesh.hpp"

#include "tests/fixtures/graphics/MeshTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using onux::Mesh;
using onux::NullArg;

TEST_F(MeshTest, validCreation) {
    expectNoThrow([&] {
        Mesh::create(
            validVertexData,
            validTextures,
            validShaderProgram
        );
    });
}

TEST_F(MeshTest, nullShaderProgram) {
    EXPECT_THROW(
        Mesh::create(
            validVertexData,
            validTextures,
            nullptr
        ),
        NullArg
    );
}
