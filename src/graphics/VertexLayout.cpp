#include "graphics/VertexLayout.hpp"

#include "gl/interfaces/IVertexAttribute.hpp"

namespace onux {

struct VertexLayout::Impl {
  Attributes    attributes;
  const GLsizei stride;

  Impl(Attributes& attributes);
};

VertexLayout::VertexLayout(Attributes& attributes)
  : impl(new Impl(attributes)) {}

VertexLayout::~VertexLayout() {}

auto VertexLayout::getAttributes() const -> Attributes& {
  return impl->attributes;
}

const GLsizei VertexLayout::getStride() const {
  return impl->stride;
}

// Implementation

static const GLsizei calculateStride(IVertexLayout::Attributes& attributes) {
  GLsizei stride = 0;

  for (auto attribute : attributes) {
    stride += attribute->getSize();
  }

  return stride;
}

VertexLayout::Impl::Impl(Attributes& attributes)
  : attributes(attributes)
  , stride(calculateStride(this->attributes)) {}

} // namespace onux
