#pragma once

#include <memory>
#include <GL/glew.h>

namespace onux {

class GLData {
public:
  const GLuint& getID() const;

protected:
  GLData(const GLuint id);

private:
  struct Impl;
  std::shared_ptr<Impl> impl;
};

} // namespace onux
