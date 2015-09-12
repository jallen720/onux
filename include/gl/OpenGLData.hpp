#pragma once

#include <GL/glew.h>

namespace onux {

class OpenGLData {
public:
  const GLuint& getID() const;

protected:
  OpenGLData(const GLuint id);

private:
  const GLuint m_id;
};

} // namespace onux
