#pragma once

#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include "gl/GLData.hpp"
#include "gl/ShaderObject.hpp"

namespace onux {

class ShaderProgram : public GLData {
public:
    using Ptr     = std::unique_ptr<const ShaderProgram>;
    using Objects = std::vector<ShaderObject::Ptr>;

public:
    static Ptr create(const Objects& objects);

public:
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

    ShaderProgram(const GLuint id, const Objects& objects);
};

} // namespace onux
