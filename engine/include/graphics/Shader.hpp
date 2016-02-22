#pragma once

#include <memory>

#include "resources/Resources.hpp"

namespace onux {

struct IShaderFile;
class ShaderSource;
class ShaderProgram;

class Shader {
public:
    using Ptr     = std::unique_ptr<const Shader>;
    using Sources = const Resources<ShaderSource>&;

public:
    static Ptr create(const IShaderFile* shaderFile, Sources sources);

public:
    ~Shader();
    const ShaderProgram& getProgram() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    Shader(const IShaderFile* shaderFile, Sources sources);
};

} // namespace onux
