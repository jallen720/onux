#pragma once

#include <memory>
#include <vector>

#include "gl/GLData.hpp"

namespace onux {

struct IShaderSource;

class ShaderObject : public GLData {
public:
  typedef const std::vector<const IShaderSource*>& Sources;

public:
  ShaderObject(Sources sources);
  ~ShaderObject();
  const GLenum getType() const;

private:
  struct Impl;
  std::shared_ptr<Impl> impl;
};

} // namespace onux
