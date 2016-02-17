#pragma once

#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include "gl/GLData.hpp"
#include "gl/ShaderObject.hpp"

namespace onux {

class ShaderProgram : public GLData {
public:
    using Objects = std::vector<ShaderObject::Ptr>;

public:
    explicit ShaderProgram(const Objects& objects);
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
