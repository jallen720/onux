#pragma once

#include <vector>
#include <string>
#include <glm/glm.hpp>

#include "gl/OpenGLData.hpp"

namespace onux {

class ShaderObject;

class ShaderProgram : public OpenGLData {
public:
  typedef std::vector<const ShaderObject*> Objects;

  ShaderProgram(const Objects& objects);
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
  void attach(const Objects& objects) const;
  void link() const;
  void detach(const Objects& objects) const;
  void validateLinkStatus() const;
  const bool linkingSucceeded() const;
  const GLint getInt(const GLenum parameter) const;
  const std::string getInfoLog() const;
  const GLint getUniformLocation(const GLchar* name) const;
};

} // namespace onux
