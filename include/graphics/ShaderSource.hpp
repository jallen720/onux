#pragma once

#include <memory>
#include <string>
#include <map>

#include "gl/interfaces/IShaderSource.hpp"

namespace onux {

class ShaderSource : public IShaderSource {
public:
    using Types = const std::map<const std::string, const GLenum>;

public:
    static Types TYPES;

public:
    ShaderSource(const std::string& path);

    // IShaderSource
    virtual const GLenum getType() const override;
    virtual const GLchar* getCode() const override;

private:
    struct Impl;
    std::shared_ptr<Impl> impl;
};

} // namespace onux
