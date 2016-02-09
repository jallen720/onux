#pragma once

#include <memory>
#include <string>

namespace onux {

class ShaderProgram;
class ShaderSources;

class Shader {
public:
    Shader(const std::string& path, const ShaderSources& shaderSources);
    ~Shader();
    const ShaderProgram& getProgram() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
