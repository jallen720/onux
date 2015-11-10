#include "gl/BufferObject.hpp"

namespace onux {

struct BufferObject::Impl {
  typedef const BufferObject* Self;

  const GLenum  target;
  const GLsizei size;
  const GLvoid* data;
  const GLenum  usage;
  Self          self;

  Impl(
    const GLenum  target,
    const GLsizei size,
    const GLvoid* data,
    const GLenum  usage,
    Self          self
  );
  void bind() const;
};

// BufferObject represents 1 buffer.
static const GLsizei BUFFER_COUNT = 1;

static GLuint newBufferObject() {
  GLuint id;
  glGenBuffers(BUFFER_COUNT, &id);
  return id;
}

void BufferObject::loadData() const {
  impl->bind();

  glBufferData(
    impl->target,
    impl->size,
    impl->data,
    impl->usage
  );
}

BufferObject::BufferObject(
  const GLenum  target,
  const GLsizei size,
  const GLvoid* data,
  const GLenum  usage
) : OpenGLData(newBufferObject())
  , impl(new Impl(target, size, data, usage, this)) {}

BufferObject::~BufferObject() {
  glDeleteBuffers(BUFFER_COUNT, &getID());
}

// Implementation

BufferObject::Impl::Impl(
  const GLenum  target,
  const GLsizei size,
  const GLvoid* data,
  const GLenum  usage,
  Self          self
) : target(target)
  , size(size)
  , data(data)
  , usage(usage)
  , self(self) {}

void BufferObject::Impl::bind() const {
  glBindBuffer(target, self->getID());
}

} // namespace onux
