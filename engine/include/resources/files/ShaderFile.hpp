#pragma once

#include <memory>
#include <string>

#include "graphics/interfaces/IShaderFile.hpp"

namespace onux {

class ShaderFile : public IShaderFile {
public:
    explicit ShaderFile(const std::string& path);
    ~ShaderFile();

    // IShaderFile
    virtual void forEachShaderObjectData(ShaderObjectDataCB shaderObjectDataCB) const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
