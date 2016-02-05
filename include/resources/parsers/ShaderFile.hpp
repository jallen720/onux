#pragma once

#include <memory>
#include <vector>
#include <string>
#include <map>

namespace onux {

class ShaderFile {
public:
    typedef std::vector<std::string> SourceList;

public:
    explicit ShaderFile(const std::string& path);
    ~ShaderFile();
    const SourceList& getSources(const std::string& path) const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
