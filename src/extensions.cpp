#include "extensions.hpp"

#include <GL/glew.h>

void loadExtensions() {
  glewExperimental = GL_TRUE;
  glewInit();
}
