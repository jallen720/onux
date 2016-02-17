#include "resources/loaders/ShaderLoader.hpp"

#include "resources/containers/ShaderSources.hpp"
#include "resources/files/ShaderFile.hpp"

using std::string;

namespace onux {

struct ShaderLoader::Impl {
    const ShaderSources& shaderSources;
};

ShaderLoader::ShaderLoader(const ShaderSources& shaderSources)
    : impl(new Impl { shaderSources }) {}

ShaderLoader::~ShaderLoader() {}

const string& ShaderLoader::getSubDirectory() const {
    static const string SUB_DIRECTORY = "shaders/";
    return SUB_DIRECTORY;
}

auto ShaderLoader::load(const string& path) const -> Resource {
    return Resource(new Shader(ShaderFile(path), impl->shaderSources));
}

} // namespace onux
