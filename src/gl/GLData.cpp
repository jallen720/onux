#include "gl/GLData.hpp"

namespace onux {

struct GLData::Impl {
    const GLuint id;
};

const GLuint& GLData::getID() const {
    return impl->id;
}

GLData::GLData(const GLuint id)
    : impl(new Impl({ id })) {}

} // namespace onux
