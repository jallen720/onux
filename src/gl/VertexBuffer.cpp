#include "gl/VertexBuffer.hpp"

#include "gl/interfaces/IVertexLayout.hpp"
#include "gl/interfaces/IVertexAttribute.hpp"
#include "gl/interfaces/IBufferData.hpp"

namespace onux {

struct VertexBuffer::Impl {
    const IVertexLayout& layout;

    Impl(const IVertexLayout& layout);
    void defineLayout() const;
};

VertexBuffer::VertexBuffer(
    const IVertexLayout& layout,
    const IBufferData&   data,
    const GLenum         usage
)   : BufferObject(
        GL_ARRAY_BUFFER,
        data.getSize(),
        data.getPointer(),
        usage
    )
    , impl(new Impl(layout)) {}

VertexBuffer::~VertexBuffer() {}

void VertexBuffer::loadData() const {
    BufferObject::loadData();
    impl->defineLayout();
}

// Implementation

static void setAttributePointer(
    const IVertexAttribute* attribute,
    const GLuint            index,
    const GLsizei           stride
) {
    glEnableVertexAttribArray(index);

    glVertexAttribPointer(
        index,
        attribute->getElementCount(),
        attribute->getType(),
        attribute->getIsNormalized(),
        stride,
        attribute->getOffset()
    );
}

static void setAttributePointers(const GLsizei stride, IVertexLayout::Attributes& attributes) {
    for (GLuint index = 0u; index < attributes.size(); index++) {
        setAttributePointer(
            attributes[index],
            index,
            stride
        );
    }
}

VertexBuffer::Impl::Impl(const IVertexLayout& layout)
    : layout(layout) {}

void VertexBuffer::Impl::defineLayout() const {
    setAttributePointers(
        layout.getStride(),
        layout.getAttributes()
    );
}

} // namespace onux
