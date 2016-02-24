#pragma once

#include <memory>
#include <string>
#include <functional>

namespace onux {

class ShaderObjectData;

class ShaderFile {
public:
    using Ptr                = std::unique_ptr<const ShaderFile>;
    using ShaderObjectDataCB = const std::function<void(const ShaderObjectData&)>&;

public:
    static Ptr create(const std::string& path);

public:
    ~ShaderFile();
    void forEachShaderObjectData(ShaderObjectDataCB shaderObjectDataCB) const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    explicit ShaderFile(const std::string& path);
};

} // namespace onux
