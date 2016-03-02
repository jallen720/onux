#include "assets/utils/loadModels.hpp"

#include "tests/fixtures/assets/utils/loadModelsTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "assets/Model.hpp"

TEST_F(loadModelsTest, loadFromValidData) {
    expectNoThrow([&] {
        loadModels(
            validResourceManager.getModelScenes(),
            validAssetManager.getShaderPrograms(),
            validAssetManager.getTextures()
        );
    });
}
