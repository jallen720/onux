#include "resources/ResourceManager.hpp"

#include "exceptions/validators/validateNotEmpty.hpp"
#include "resources/utils/loadResources.hpp"
#include "resources/Shader.hpp"
#include "resources/ShaderSource.hpp"
#include "resources/Image.hpp"
#include "resources/Model.hpp"

using std::string;

namespace onux {

struct ResourceManager::Impl {
    UniqueMap<Shader>       shaders;
    UniqueMap<ShaderSource> shaderSources;
    UniqueMap<Image>        images;
    UniqueMap<Model>        models;

    Impl(const string& directory);
};

static const string& getValidDirectory(const string& directory) {
    validateNotEmpty(
        "directory",
        "ResourceManager::ResourceManager",
        directory
    );

    return directory;
}

ResourceManager::ResourceManager(const string& directory)
    : impl(new Impl(getValidDirectory(directory))) {}

ResourceManager::~ResourceManager() {}

const UniqueMap<Shader>& ResourceManager::getShaders() const {
    return impl->shaders;
}

const UniqueMap<ShaderSource>& ResourceManager::getShaderSources() const {
    return impl->shaderSources;
}

const UniqueMap<Image>& ResourceManager::getImages() const {
    return impl->images;
}

const UniqueMap<Model>& ResourceManager::getModels() const {
    return impl->models;
}

// Implementation

ResourceManager::Impl::Impl(const string& directory)
    : shaders      (loadResources<Shader>      (directory + "/shaders"))
    , shaderSources(loadResources<ShaderSource>(directory + "/shaderSources"))
    , images       (loadResources<Image>       (directory + "/images"))
    , models       (loadResources<Model>       (directory + "/models")) {}

} // namespace onux
