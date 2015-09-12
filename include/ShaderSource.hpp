#pragma once

#include <string>
#include <map>

#include "onux_gl/IShaderSource.hpp"

class ShaderSource : public onux_gl::IShaderSource {
public:
  typedef std::map<const std::string, const GLenum> Types;

  static const Types TYPES;

  ShaderSource(const std::string& path);

  // onux_gl::IShaderSource
  const GLenum getType() const override;
  const GLchar* getCode() const override;

private:
  const GLenum      m_type;
  const std::string m_code;
};
