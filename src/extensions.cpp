#include "extensions.hpp"

#include <stdexcept>
#include <GL/glew.h>

using std::runtime_error;

static void setExperimental() {
  glewExperimental = GL_TRUE;
}

static void validateInit(const GLenum initResult) {
  if (initResult != GLEW_OK) {
    throw runtime_error("GLEW failed to initialize!");
  }
}

void loadExtensions() {
  setExperimental();
  validateInit(glewInit());
}
