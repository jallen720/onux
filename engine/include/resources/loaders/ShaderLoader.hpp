#pragma once

#include <memory>

#include "resources/loaders/ResourceLoader.hpp"
#include "graphics/Shader.hpp"

namespace onux {

class ShaderSources;

class ShaderLoader : public ResourceLoader<const Shader> {
public:
    ShaderLoader(const ShaderSources& shaderSources);
    ~ShaderLoader();

protected:
    // ResourceLoader
    virtual const std::string& getSubDirectory() const override;
    virtual Resource load(const std::string& path) const override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
