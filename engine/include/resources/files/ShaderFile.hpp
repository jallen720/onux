#pragma once

#include <memory>
#include <string>

#include "graphics/interfaces/IShaderFile.hpp"

namespace onux {

class ShaderFile : public IShaderFile {
public:
    using Ptr = std::unique_ptr<const ShaderFile>;

public:
    static Ptr create(const std::string& path);

public:
    ~ShaderFile();

    // IShaderFile
    virtual void forEachShaderObjectData(ShaderObjectDataCB shaderObjectDataCB) const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    explicit ShaderFile(const std::string& path);
};

} // namespace onux
