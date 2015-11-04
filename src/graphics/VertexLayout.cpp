#include "graphics/VertexLayout.hpp"

#include "gl/interfaces/IVertexAttribute.hpp"

namespace onux {

static const GLsizei calculateStride(IVertexLayout::Attributes& attributes) {
  GLsizei stride = 0;

  for (auto attribute : attributes) {
    stride += attribute->getSize();
  }

  return stride;
}

VertexLayout::VertexLayout(Attributes& attributes)
  : m_attributes(attributes)
  , m_stride(calculateStride(m_attributes)) {}

auto VertexLayout::getAttributes() const -> Attributes& {
  return m_attributes;
}

const GLsizei VertexLayout::getStride() const {
  return m_stride;
}

} // namespace onux
