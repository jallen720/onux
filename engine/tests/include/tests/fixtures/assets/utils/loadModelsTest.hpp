#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "resources/ResourceManager.hpp"
#include "assets/AssetManager.hpp"

struct loadModelsTest : OnuxTest {
protected:
    const onux::ResourceManager validResourceManager { "tests/resources/valid/" };
    const onux::AssetManager    validAssetManager { validResourceManager };
};
