#pragma once

#include <vector>
#include <string>
#include <glm/glm.hpp>

#include "OpenGLData.hpp"

using std::vector;
using std::string;
using glm::vec4;

class ShaderObject;

class ShaderProgram : public OpenGLData {
public:
  typedef const vector<const ShaderObject*>& Objects;

private:
  void attach(Objects objects) const;
  void link() const;
  void detach(Objects objects) const;
  void validateLinkStatus() const;
  const bool linkingSucceeded() const;
  const GLint getInt(const GLenum parameter) const;
  const string getInfoLog() const;
  const GLint getUniformLocation(const GLchar* name) const;

public:
  ShaderProgram(Objects objects);
  ~ShaderProgram();
  void use() const;
  void setUniform(const GLchar* name, const vec4& value) const;
};