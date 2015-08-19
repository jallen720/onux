#pragma once

#include <vector>
#include <string>

#include "onux_gl/OpenGLData.hpp"

namespace onux_gl {
  using std::vector;
  using std::string;

  struct IShaderSource;

  class ShaderObject : public OpenGLData {
  public:
    typedef const vector<const IShaderSource*>& Sources;

  private:
    void loadSources(Sources sources) const;
    void compile() const;
    void validateCompileStatus() const;
    const bool compilationSucceeded() const;
    const GLint getInt(const GLenum parameter) const;
    const string getInfoLog() const;

  public:
    ShaderObject(Sources sources);
    ~ShaderObject();
    const GLenum getType() const;
  };
}
