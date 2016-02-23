#include "resources/ResourceManager.hpp"

#include "exceptions/validators/validateNotEmpty.hpp"

using std::string;

namespace onux {

struct ResourceManager::Impl {
    Resources<ShaderFile>   shaderFiles;
    Resources<ShaderSource> shaderSources;
    Resources<Image>        images;
    Resources<Model>        models;

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

const Resources<ShaderFile>& ResourceManager::getShaderFiles() const {
    return impl->shaderFiles;
}

const Resources<ShaderSource>& ResourceManager::getShaderSources() const {
    return impl->shaderSources;
}

const Resources<Image>& ResourceManager::getImages() const {
    return impl->images;
}

const Resources<Model>& ResourceManager::getModels() const {
    return impl->models;
}

// Implementation

ResourceManager::Impl::Impl(const string& resourcesDirectory)
    : shaderFiles(resourcesDirectory + "/shaders")
    , shaderSources(resourcesDirectory + "/shaderSources")
    , images(resourcesDirectory + "/images")
    , models(resourcesDirectory + "/models") {}

} // namespace onux
