#pragma once

#include <vector>
#include <string>

#include "OpenGLData.hpp"

using std::vector;
using std::string;

class ShaderSource;

class ShaderObject : public OpenGLData {
public:
  typedef const vector<const ShaderSource*>& Sources;

private:
  void loadSources(Sources sources) const;
  void compile() const;
  void validateCompileStatus() const;
  const bool compilationFailed() const;
  const GLint getInt(const GLenum parameter) const;
  const string getInfoLog() const;

public:
  ShaderObject(Sources sources);
  ~ShaderObject();
};
