#pragma once

#include <memory>
#include <string>
#include <functional>

namespace onux {

class ShaderObjectData;

class Shader {
public:
    using Ptr                = std::unique_ptr<const Shader>;
    using ShaderObjectDataCB = const std::function<void(const ShaderObjectData&)>&;

public:
    static Ptr create(const std::string& path);

public:
    ~Shader();
    void forEachShaderObjectData(ShaderObjectDataCB shaderObjectDataCB) const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    explicit Shader(const std::string& path);
};

} // namespace onux
