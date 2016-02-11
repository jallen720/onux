#pragma once

#include <memory>
#include <vector>
#include <string>

#include "graphics/interfaces/IShaderObjectData.hpp"

namespace onux {

class ShaderObjectData : public IShaderObjectData {
public:
    using Ptr = std::unique_ptr<const ShaderObjectData>;

public:
    ShaderObjectData(const std::string& type, const SourcePaths& SourcePaths);
    ~ShaderObjectData();

    // IShaderObjectData
    virtual const std::string& getType() const override;
    virtual const SourcePaths& getSourcePaths() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
