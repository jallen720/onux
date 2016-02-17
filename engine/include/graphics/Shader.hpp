#pragma once

#include <memory>

namespace onux {

struct IShaderFile;
class ShaderSources;
class ShaderProgram;

class Shader {
public:
    Shader(const IShaderFile& shaderFile, const ShaderSources& shaderSources);
    ~Shader();
    const ShaderProgram& getProgram() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
