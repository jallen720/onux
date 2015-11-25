#include "gl/GLData.hpp"

namespace onux {

struct GLData::Impl {
    const GLuint id;

    Impl(const GLuint id);
};

const GLuint& GLData::getID() const {
    return impl->id;
}

GLData::GLData(const GLuint id)
    : impl(new Impl(id)) {}

// Implementation

GLData::Impl::Impl(const GLuint id)
    : id(id) {}

} // namespace onux
