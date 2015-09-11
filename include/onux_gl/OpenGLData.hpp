#pragma once

#include <GL/glew.h>

namespace onux_gl {

class OpenGLData {
public:
  const GLuint& getID() const;

protected:
  OpenGLData(const GLuint id);

private:
  const GLuint id;
};

} // namespace onux_gl
