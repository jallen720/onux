#pragma once

#include <memory>
#include <GL/glew.h>

namespace onux {

class OpenGLData {
public:
  const GLuint& getID() const;

protected:
  OpenGLData(const GLuint id);

private:
  struct Impl;
  std::shared_ptr<Impl> impl;
};

} // namespace onux
