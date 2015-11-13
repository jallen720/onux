#include "gl/BufferObject.hpp"

#include <stdexcept>
#include <vector>

#include "utils/contains.hpp"

using std::runtime_error;
using std::vector;

namespace onux {

struct BufferObject::Impl {
  typedef const BufferObject* Self;

  const GLenum     target;
  const GLsizeiptr size;
  const GLvoid*    data;
  const GLenum     usage;
  Self             self;

  Impl(
    const GLenum     target,
    const GLsizeiptr size,
    const GLvoid*    data,
    const GLenum     usage,
    Self             self
  );
  void bind() const;
};

void BufferObject::loadData() const {
  impl->bind();

  glBufferData(
    impl->target,
    impl->size,
    impl->data,
    impl->usage
  );
}

static bool isValidTarget(const GLenum target) {
  static const vector<GLenum> VALID_TARGETS {
    GL_ARRAY_BUFFER,
    GL_COPY_READ_BUFFER,
    GL_COPY_WRITE_BUFFER,
    GL_ELEMENT_ARRAY_BUFFER,
    GL_PIXEL_PACK_BUFFER,
    GL_PIXEL_UNPACK_BUFFER,
    GL_TEXTURE_BUFFER,
    GL_TRANSFORM_FEEDBACK_BUFFER,
    GL_UNIFORM_BUFFER,
  };

  return contains(VALID_TARGETS, target);
}

static void validateTarget(const GLenum target) {
  if (!isValidTarget(target)) {
    throw runtime_error("Invalid target parameter passed to BufferObject!");
  }
}

static void validateSize(const GLsizeiptr size) {
  if (size < 0) {
    throw runtime_error("Size parameter passed to BufferObject cannot be negative!");
  }
}

static bool isValidUsage(const GLenum usage) {
  static const vector<GLenum> VALID_USAGES {
    GL_STREAM_DRAW,
    GL_STREAM_READ,
    GL_STREAM_COPY,
    GL_STATIC_DRAW,
    GL_STATIC_READ,
    GL_STATIC_COPY,
    GL_DYNAMIC_DRAW,
    GL_DYNAMIC_READ,
    GL_DYNAMIC_COPY,
  };

  return contains(VALID_USAGES, usage);
}

static void validateUsage(const GLenum usage) {
  if (!isValidUsage(usage)) {
    throw runtime_error("Invalid usage parameter passed to BufferObject!");
  }
}

// BufferObject represents 1 buffer.
static const GLsizeiptr BUFFER_COUNT = 1;

static GLuint createBufferObject() {
  GLuint id;
  glGenBuffers(BUFFER_COUNT, &id);
  return id;
}

static GLuint loadBufferObject(
  const GLenum     target,
  const GLsizeiptr size,
  const GLenum     usage
) {
  validateTarget(target);
  validateSize(size);
  validateUsage(usage);
  return createBufferObject();
}

BufferObject::BufferObject(
  const GLenum     target,
  const GLsizeiptr size,
  const GLvoid*    data,
  const GLenum     usage
) : OpenGLData(loadBufferObject(target, size, usage))
  , impl(new Impl(target, size, data, usage, this)) {}

BufferObject::~BufferObject() {
  glDeleteBuffers(BUFFER_COUNT, &getID());
}

// Implementation

BufferObject::Impl::Impl(
  const GLenum     target,
  const GLsizeiptr size,
  const GLvoid*    data,
  const GLenum     usage,
  Self             self
) : target(target)
  , size(size)
  , data(data)
  , usage(usage)
  , self(self) {}

void BufferObject::Impl::bind() const {
  glBindBuffer(target, self->getID());
}

} // namespace onux
