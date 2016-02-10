#pragma once

#include <memory>
#include <vector>

#include "gl/GLData.hpp"

namespace onux {

struct IShaderSource;

class ShaderObject : public GLData {
public:
    using Sources = std::vector<const IShaderSource*>;

public:
    explicit ShaderObject(const Sources& sources);
    ~ShaderObject();
    const GLenum getType() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
