#pragma once

#include <vector>
#include <string>

#include "gl/OpenGLData.hpp"

namespace onux {

struct IShaderSource;

class ShaderObject : public OpenGLData {
public:
  typedef const std::vector<const IShaderSource*>& Sources;

public:
  ShaderObject(Sources sources);
  ~ShaderObject();
  const GLenum getType() const;

private:
  void loadSources(Sources sources) const;
  void compile() const;
  void validateCompileStatus() const;
  const bool compilationSucceeded() const;
  const GLint getInt(const GLenum parameter) const;
  const std::string getInfoLog() const;
};

} // namespace onux
