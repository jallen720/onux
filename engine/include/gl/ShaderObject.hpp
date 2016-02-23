#pragma once

#include <memory>
#include <vector>

#include "gl/GLData.hpp"

namespace onux {

struct IShaderSource;

class ShaderObject : public GLData {
public:
    using Ptr     = std::unique_ptr<const ShaderObject>;
    using Sources = std::vector<const IShaderSource*>;

public:
    static Ptr create(const Sources& sources);

public:
    ~ShaderObject();
    const GLenum getType() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    ShaderObject(const GLuint id, const Sources& sources);
};

} // namespace onux
