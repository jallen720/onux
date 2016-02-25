#pragma once

#include <memory>
#include <vector>
#include <string>

#include "MACROS/ONUX_MOVE_ONLY_DEFS.hpp"

namespace onux {

class ShaderObjectData {
public:
    using SourcePaths = std::vector<std::string>;

public:
    ShaderObjectData(const std::string& type, const SourcePaths& SourcePaths);
    ONUX_MOVE_ONLY_DEFS(ShaderObjectData)
    const std::string& getType() const;
    const SourcePaths& getSourcePaths() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
