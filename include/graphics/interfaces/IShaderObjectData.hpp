#pragma once

#include <string>
#include <vector>

namespace onux {

struct IShaderObjectData {
    using SourcePaths = std::vector<std::string>;

    virtual ~IShaderObjectData() {}
    virtual const std::string& getType() const = 0;
    virtual const SourcePaths& getSourcePaths() const = 0;
};

} // namespace onux
