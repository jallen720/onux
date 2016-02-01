#include "graphics/Model.hpp"

#include "fixtures/graphics/ModelTest.hpp"
#include "utils/expectNoThrow.hpp"
#include "utils/testModelPath.hpp"
#include "exceptions/subsystemErrors/AssimpError.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using onux::Model;
using onux::AssimpError;
using onux::EmptyStringArg;

TEST_F(ModelTest, validCreation) {
    expectNoThrow([] {
        const Model model(testModelPath("cube.obj"));
    });
}

TEST_F(ModelTest, validData) {
    const Model model(testModelPath("cube.obj"));

    // Cube model should have 1 mesh
    ASSERT_EQ(1, model.getMeshes().size());
}

TEST_F(ModelTest, emptyPath) {
    EXPECT_THROW(
        const Model model(""),
        EmptyStringArg
    );
}

TEST_F(ModelTest, invalidPath) {
    EXPECT_THROW(
        const Model model("invalid/path"),
        AssimpError
    );
}
