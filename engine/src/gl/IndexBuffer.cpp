#include "gl/IndexBuffer.hpp"

#include "gl/interfaces/IBufferData.hpp"

namespace onux {

IndexBuffer::IndexBuffer(const IBufferData& data, const GLenum usage)
    : BufferObject(
        GL_ELEMENT_ARRAY_BUFFER,
        data.getSize(),
        data.getPointer(),
        usage
    ) {}

} // namespace onux
