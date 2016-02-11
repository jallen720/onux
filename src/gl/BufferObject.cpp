#include "gl/BufferObject.hpp"

#include <vector>
#include <string>

#include "exceptions/argErrors/InvalidArg.hpp"
#include "utils/toString.hpp"
#include "gl/utils/ValidValues.hpp"

#include "MACROS/VALID_VALUE.hpp"

using std::vector;
using std::string;

namespace onux {

struct BufferObject::Impl {
    const GLuint     id;
    const GLenum     target;
    const GLsizeiptr size;
    const GLvoid*    data;
    const GLenum     usage;

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

static void validateTarget(const GLenum target) {
    static const ValidValues VALID_TARGETS({
        VALID_VALUE(GL_ARRAY_BUFFER),
        VALID_VALUE(GL_COPY_READ_BUFFER),
        VALID_VALUE(GL_COPY_WRITE_BUFFER),
        VALID_VALUE(GL_ELEMENT_ARRAY_BUFFER),
        VALID_VALUE(GL_PIXEL_PACK_BUFFER),
        VALID_VALUE(GL_PIXEL_UNPACK_BUFFER),
        VALID_VALUE(GL_TEXTURE_BUFFER),
        VALID_VALUE(GL_TRANSFORM_FEEDBACK_BUFFER),
        VALID_VALUE(GL_UNIFORM_BUFFER),
    });

    if (!VALID_TARGETS.contains(target)) {
        throw InvalidArg(
            "target",
            "BufferObject::BufferObject",
            VALID_TARGETS.getNames()
        );
    }
}

static void validateSize(const GLsizeiptr size) {
    static const GLsizeiptr MIN_SIZE = 0;

    if (size < MIN_SIZE) {
        throw InvalidArg(
            "size",
            "BufferObject::BufferObject",
            ">= " + toString(MIN_SIZE)
        );
    }
}

static void validateUsage(const GLenum usage) {
    static const ValidValues VALID_USAGES({
        VALID_VALUE(GL_STREAM_DRAW),
        VALID_VALUE(GL_STREAM_READ),
        VALID_VALUE(GL_STREAM_COPY),
        VALID_VALUE(GL_STATIC_DRAW),
        VALID_VALUE(GL_STATIC_READ),
        VALID_VALUE(GL_STATIC_COPY),
        VALID_VALUE(GL_DYNAMIC_DRAW),
        VALID_VALUE(GL_DYNAMIC_READ),
        VALID_VALUE(GL_DYNAMIC_COPY),
    });

    if (!VALID_USAGES.contains(usage)) {
        throw InvalidArg(
            "usage",
            "BufferObject::BufferObject",
            VALID_USAGES.getNames()
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

static GLuint getValidBufferObject(
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
)   : GLData(getValidBufferObject(target, size, usage))
    , impl(new Impl {
        getID(),
        target,
        size,
        data,
        usage
    }) {

}

BufferObject::~BufferObject() {
    glDeleteBuffers(BUFFER_COUNT, &getID());
}

// Implementation

void BufferObject::Impl::bind() const {
    glBindBuffer(target, id);
}

} // namespace onux
