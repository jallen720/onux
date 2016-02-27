#include "assets/AssetManager.hpp"

#include "assets/utils/loadShaderPrograms.hpp"
#include "assets/utils/loadTextures.hpp"
#include "gl/ShaderProgram.hpp"
#include "gl/Texture.hpp"
#include "resources/ResourceManager.hpp"

namespace onux {

struct AssetManager::Impl {
    UniqueMap<ShaderProgram> shaderPrograms;
    UniqueMap<Texture>       textures;

    Impl(const ResourceManager& resourceManager);
};

AssetManager::AssetManager(const ResourceManager& resourceManager)
    : impl(new Impl(resourceManager)) {}

AssetManager::~AssetManager() {}

const UniqueMap<ShaderProgram>& AssetManager::getShaderPrograms() const {
    return impl->shaderPrograms;
}

const UniqueMap<Texture>& AssetManager::getTextures() const {
    return impl->textures;
}

// Implementation

AssetManager::Impl::Impl(const ResourceManager& resourceManager)
    : shaderPrograms(loadShaderPrograms(
        resourceManager.getShaders(),
        resourceManager.getShaderSources()
    ))
    , textures(loadTextures(resourceManager.getImages())) {}

} // namespace onux
