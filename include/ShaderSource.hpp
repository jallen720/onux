#pragma once

#include <string>
#include <map>
#include <GL/glew.h>

using std::string;
using std::map;

class ShaderSource {
  const GLenum type;
  const string code;

public:
  typedef const map<const string, const GLenum> Types;
  static Types types;

  ShaderSource(const string& path);
  const GLenum getType() const;
  const GLchar* getCode() const;
};
