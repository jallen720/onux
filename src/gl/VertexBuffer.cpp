#include "gl/VertexBuffer.hpp"

#include "gl/interfaces/IVertexLayout.hpp"
#include "gl/interfaces/IVertexAttribute.hpp"
#include "gl/IBufferData.hpp"

namespace onux {

VertexBuffer::VertexBuffer(
  const IVertexLayout& layout,
  const IBufferData&   data,
  const GLenum         usage
) : BufferObject(
      GL_ARRAY_BUFFER,
      data.getSize(),
      data.getPointer(),
      usage
    )
  , m_layout(layout) {}

void VertexBuffer::loadData() const {
  BufferObject::loadData();
  defineLayout();
}

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

void VertexBuffer::defineLayout() const {
  setAttributePointers(
    m_layout.getStride(),
    m_layout.getAttributes()
  );
}

} // namespace onux
