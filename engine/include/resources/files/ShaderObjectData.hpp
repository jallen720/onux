#pragma once

#include <memory>
#include <vector>
#include <string>

namespace onux {

class ShaderObjectData {
public:
    using Ptr         = std::unique_ptr<const ShaderObjectData>;
    using SourcePaths = std::vector<std::string>;

public:
    ShaderObjectData(const std::string& type, const SourcePaths& SourcePaths);
    ~ShaderObjectData();
    const std::string& getType() const;
    const SourcePaths& getSourcePaths() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
