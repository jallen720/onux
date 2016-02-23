#include "assets/AssetManager.hpp"

#include "resources/ResourceManager.hpp"
#include "assets/Shaders.hpp"
#include "assets/Textures.hpp"

namespace onux {

struct AssetManager::Impl {
    Shaders  shaders;
    Textures textures;

    Impl(const ResourceManager& resourceManager);
};

AssetManager::AssetManager(const ResourceManager& resourceManager)
    : impl(new Impl(resourceManager)) {}

AssetManager::~AssetManager() {}

const Shaders& AssetManager::getShaders() const {
    return impl->shaders;
}

const Textures& AssetManager::getTextures() const {
    return impl->textures;
}

// Implementation

AssetManager::Impl::Impl(const ResourceManager& resourceManager)
    : shaders(
        resourceManager.getShaderFiles(),
        resourceManager.getShaderSources()
    )
    , textures(resourceManager.getImages()) {}

} // namespace onux
