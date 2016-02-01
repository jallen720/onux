#include "resources/ResourceManager.hpp"

#include "resources/containers/ShaderSources.hpp"
#include "resources/containers/Images.hpp"
#include "resources/containers/Models.hpp"

using std::string;

namespace onux {

struct ResourceManager::Impl {
    const ShaderSources shaderSources;
    const Images images;
    const Models models;
};

const string& ResourceManager::DEFAULT_RESOURCES_DIRECTORY = "resources/";

ResourceManager::ResourceManager(const string& resourcesDirectory)
    : impl(new Impl {}) {}

ResourceManager::~ResourceManager() {}

const ShaderSources& ResourceManager::getShaderSources() const {
    return impl->shaderSources;
}

const Images& ResourceManager::getImages() const {
    return impl->images;
}

const Models& ResourceManager::getModels() const {
    return impl->models;
}

} // namespace onux

