#pragma once

#include <memory>
#include <string>
#include <map>

#include "gl/interfaces/IShaderSource.hpp"

namespace onux {

class ShaderSource : public IShaderSource {
public:
    using Ptr   = std::unique_ptr<const ShaderSource>;
    using Types = const std::map<const std::string, const GLenum>;

public:
    static Types TYPES;

    static Ptr create(const std::string& path);

public:
    ~ShaderSource();

    // IShaderSource
    virtual const GLenum getType() const override;
    virtual const GLchar* getCode() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    ShaderSource(const std::string& path);
};

} // namespace onux
