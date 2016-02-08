#pragma once

#include <memory>
#include <vector>

#include "gl/GLData.hpp"

namespace onux {

struct IShaderSource;

class ShaderObject : public GLData {
public:
    typedef std::vector<const IShaderSource*> Sources;

public:
    explicit ShaderObject(const Sources& sources);
    ~ShaderObject();
    const GLenum getType() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
