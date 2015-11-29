#pragma once

#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include "gl/GLData.hpp"

namespace onux {

class ShaderObject;

class ShaderProgram : public GLData {
public:
    typedef const std::vector<const ShaderObject*>& Objects;

public:
    ShaderProgram(Objects objects);
    ~ShaderProgram();
    void use() const;
    void setUniform(const GLchar* name, const GLint value) const;
    void setUniform(const GLchar* name, const glm::vec3& value) const;
    void setUniform(const GLchar* name, const glm::vec4& value) const;
    void setUniform(
        const GLchar*    name,
        const glm::mat4& value,
        const GLboolean  transpose = GL_FALSE
    ) const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
