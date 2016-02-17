#include "gl/utils/getInt.hpp"

namespace onux {

const GLint getInt(const GLenum parameter) {
    GLint value;
    glGetIntegerv(parameter, &value);
    return value;
}

} // namespace onux
