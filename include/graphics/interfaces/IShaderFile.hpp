#pragma once

#include <string>
#include <vector>
#include <functional>

#include "graphics/interfaces/IShaderObjectData.hpp"

namespace onux {

struct IShaderFile {
    using ShaderObjectDataCB = const std::function<void(const IShaderObjectData&)>&;

    virtual ~IShaderFile() {}
    virtual void forEachShaderObjectData(ShaderObjectDataCB shaderObjectDataCB) const = 0;
};

} // namespace onux
