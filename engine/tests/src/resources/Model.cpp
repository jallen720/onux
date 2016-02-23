#include "resources/Model.hpp"

#include "tests/fixtures/resources/ModelTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "tests/utils/validResourcePath.hpp"
#include "exceptions/subsystemErrors/AssimpError.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using onux::Model;
using onux::AssimpError;
using onux::EmptyStringArg;

TEST_F(ModelTest, validCreation) {
    expectNoThrow([] {
        Model::create(validResourcePath("models", "cube.obj"));
    });
}

TEST_F(ModelTest, validData) {
    // Cube model should have 1 mesh
    ASSERT_EQ(
        1,
        Model::create(validResourcePath("models", "cube.obj"))
            ->getMeshes()
            .size()
    );
}

TEST_F(ModelTest, emptyPath) {
    EXPECT_THROW(Model::create(""), EmptyStringArg);
}

TEST_F(ModelTest, invalidPath) {
    EXPECT_THROW(Model::create("invalid/path"), AssimpError);
}
