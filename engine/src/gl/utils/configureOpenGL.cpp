#include "gl/utils/configureOpenGL.hpp"

#include <GL/glew.h>

namespace onux {

void configureOpenGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
}

} // namespace onux
