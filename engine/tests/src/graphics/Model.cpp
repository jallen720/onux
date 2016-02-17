#include "graphics/Model.hpp"

#include "tests/fixtures/graphics/ModelTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "tests/utils/testModelPath.hpp"
#include "exceptions/subsystemErrors/AssimpError.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using onux::Model;
using onux::AssimpError;
using onux::EmptyStringArg;

TEST_F(ModelTest, validCreation) {
    expectNoThrow([] {
        Model(testModelPath("cube.obj"));
    });
}

TEST_F(ModelTest, validData) {
    // Cube model should have 1 mesh
    ASSERT_EQ(1, Model(testModelPath("cube.obj")).getMeshes().size());
}

TEST_F(ModelTest, emptyPath) {
    EXPECT_THROW(Model(""), EmptyStringArg);
}

TEST_F(ModelTest, invalidPath) {
    EXPECT_THROW(Model("invalid/path"), AssimpError);
}
