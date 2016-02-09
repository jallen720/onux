#pragma once

#include <memory>

#include "resources/containers/Resources.hpp"
#include "graphics/Shader.hpp"

namespace onux {

class ShaderSources;

class Shaders : public Resources<const Shader> {
public:
    Shaders(const ShaderSources& shaderSources);
    ~Shaders();

protected:
    // Resources
    virtual Loader getLoader() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
