#pragma once

#include <memory>
#include <string>
#include <map>

#include "gl/interfaces/IShaderSource.hpp"

namespace onux {

class ShaderSource : public IShaderSource {
public:
  typedef const std::map<const std::string, const GLenum> Types;

public:
  static Types TYPES;

public:
  ShaderSource(const std::string& path);

  // IShaderSource
  const GLenum getType() const override;
  const GLchar* getCode() const override;

private:
  struct Impl;
  std::shared_ptr<Impl> impl;
};

} // namespace onux
