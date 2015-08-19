#pragma once

#include <string>
#include <map>

#include "onux_gl/IShaderSource.hpp"

using std::string;
using std::map;
using onux_gl::IShaderSource;

class ShaderSource : public IShaderSource {
  const GLenum type;
  const string code;

public:
  typedef const map<const string, const GLenum> Types;
  static Types types;

  ShaderSource(const string& path);

  // IShaderSource
  const GLenum getType() const override;
  const GLchar* getCode() const override;
};
