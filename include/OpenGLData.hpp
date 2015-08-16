#pragma once

#include <GL/glew.h>

class OpenGLData {
  const GLuint id;

protected:
  OpenGLData(const GLuint id);

public:
  const GLuint& getID() const;
};
