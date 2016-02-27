#include "assets/AssetManager.hpp"

#include "assets/utils/loadShaderPrograms.hpp"
#include "assets/utils/loadTextures.hpp"
#include "assets/utils/loadModels.hpp"
#include "assets/Model.hpp"
#include "gl/ShaderProgram.hpp"
#include "gl/Texture.hpp"
#include "resources/ResourceManager.hpp"

namespace onux {

struct AssetManager::Impl {
    UniqueMap<ShaderProgram> shaderPrograms;
    UniqueMap<Texture>       textures;
    UniqueMap<Model>         models;

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

const UniqueMap<Model>& AssetManager::getModels() const {
    return impl->models;
}

// Implementation

AssetManager::Impl::Impl(const ResourceManager& resourceManager)
    : shaderPrograms(loadShaderPrograms(
        resourceManager.getShaders(),
        resourceManager.getShaderSources()
    ))
    , textures(loadTextures(resourceManager.getImages()))
    , models(loadModels(resourceManager.getModelScenes())) {}

} // namespace onux
