#include "resources/ResourceManager.hpp"

#include "exceptions/validators/validateNotEmpty.hpp"
#include "resources/Shader.hpp"
#include "resources/ShaderSource.hpp"
#include "resources/Image.hpp"
#include "resources/Model.hpp"
#include "resources/loadResources.hpp"

using std::string;

namespace onux {

struct ResourceManager::Impl {
    UniqueMap<Shader>       shaders;
    UniqueMap<ShaderSource> shaderSources;
    UniqueMap<Image>        images;
    UniqueMap<Model>        models;

    Impl(const string& resourcesDirectory);
};

static const string& getValidResourcesDirectory(const string& resourcesDirectory) {
    validateNotEmpty(
        "resourcesDirectory",
        "ResourceManager::ResourceManager",
        resourcesDirectory
    );

    return resourcesDirectory;
}

ResourceManager::ResourceManager(const string& resourcesDirectory)
    : impl(new Impl(getValidResourcesDirectory(resourcesDirectory))) {}

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

ResourceManager::Impl::Impl(const string& resourcesDirectory)
    : shaders      (loadResources<Shader>      (resourcesDirectory + "/shaders"))
    , shaderSources(loadResources<ShaderSource>(resourcesDirectory + "/shaderSources"))
    , images       (loadResources<Image>       (resourcesDirectory + "/images"))
    , models       (loadResources<Model>       (resourcesDirectory + "/models")) {}

} // namespace onux
