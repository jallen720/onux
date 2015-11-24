#include "environment/loadExtensions.hpp"

#include <GL/glew.h>

#include "exceptions/subsystemErrors/GlewError.hpp"

namespace onux {

static void setExperimental() {
  glewExperimental = GL_TRUE;
}

static void validateInit(const GLenum initResult) {
  if (initResult != GLEW_OK) {
    throw GlewError("failed to initialize");
  }
}

void loadExtensions() {
  setExperimental();
  validateInit(glewInit());
}

} // namespace onux
