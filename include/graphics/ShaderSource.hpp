#pragma once

#include <string>
#include <map>

#include "gl/interfaces/IShaderSource.hpp"

namespace onux {

class ShaderSource : public IShaderSource {
public:
  typedef std::map<const std::string, const GLenum> Types;

  static const Types TYPES;

  ShaderSource(const std::string& path);

  // IShaderSource
  const GLenum getType() const override;
  const GLchar* getCode() const override;

private:
  const GLenum      m_type;
  const std::string m_code;
};

} // namespace onux
