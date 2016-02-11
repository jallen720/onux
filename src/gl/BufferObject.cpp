#include "gl/BufferObject.hpp"

#include <vector>
#include <string>

#include "exceptions/argErrors/InvalidArg.hpp"
#include "utils/toString.hpp"
#include "gl/utils/ValidValues.hpp"

#include "MACROS/ONUX_STRINGIFY.hpp"

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
        ONUX_STRINGIFY(GL_ARRAY_BUFFER),
        ONUX_STRINGIFY(GL_COPY_READ_BUFFER),
        ONUX_STRINGIFY(GL_COPY_WRITE_BUFFER),
        ONUX_STRINGIFY(GL_ELEMENT_ARRAY_BUFFER),
        ONUX_STRINGIFY(GL_PIXEL_PACK_BUFFER),
        ONUX_STRINGIFY(GL_PIXEL_UNPACK_BUFFER),
        ONUX_STRINGIFY(GL_TEXTURE_BUFFER),
        ONUX_STRINGIFY(GL_TRANSFORM_FEEDBACK_BUFFER),
        ONUX_STRINGIFY(GL_UNIFORM_BUFFER),
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
        ONUX_STRINGIFY(GL_STREAM_DRAW),
        ONUX_STRINGIFY(GL_STREAM_READ),
        ONUX_STRINGIFY(GL_STREAM_COPY),
        ONUX_STRINGIFY(GL_STATIC_DRAW),
        ONUX_STRINGIFY(GL_STATIC_READ),
        ONUX_STRINGIFY(GL_STATIC_COPY),
        ONUX_STRINGIFY(GL_DYNAMIC_DRAW),
        ONUX_STRINGIFY(GL_DYNAMIC_READ),
        ONUX_STRINGIFY(GL_DYNAMIC_COPY),
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
