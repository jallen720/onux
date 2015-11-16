#include "gl/BufferObject.hpp"

#include <vector>
#include <string>

#include "exceptions/InvalidArg.hpp"
#include "utils/contains.hpp"
#include "utils/map.hpp"
#include "gl/utils/getEnumName.hpp"

using std::vector;
using std::string;
using std::to_string;

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

static void validateTarget(const GLenum target) {
  if (!contains(VALID_TARGETS, target)) {
    throw InvalidArg(
      "target",
      "BufferObject",
      getEnumName(target),
      map<string>(VALID_TARGETS, getEnumName)
    );
  }
}

static void validateSize(const GLsizeiptr size) {
  if (size < 0) {
    throw InvalidArg(
      "size",
      "BufferObject",
      to_string(size),
      ">= 0"
    );
  }
}

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

static void validateUsage(const GLenum usage) {
  if (!contains(VALID_USAGES, usage)) {
    throw InvalidArg(
      "usage",
      "BufferObject",
      getEnumName(usage),
      map<string>(VALID_USAGES, getEnumName)
    );
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
