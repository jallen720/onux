#include "assets/Model.hpp"

#include "tests/fixtures/resources/ModelTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using onux::Model;
using onux::NullArg;

TEST_F(ModelTest, validCreation) {
    expectNoThrow([&] {
        Model::create(cubeScene.get());
    });
}

TEST_F(ModelTest, validData) {
    // Cube model should have 1 mesh
    ASSERT_EQ(
        1,
        Model::create(cubeScene.get())
            ->getMeshes()
            .size()
    );
}

TEST_F(ModelTest, nullModelScene) {
    EXPECT_THROW(Model::create(nullptr), NullArg);
}
