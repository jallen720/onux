#include "graphics/VertexLayout.hpp"

#include "gl/interfaces/IVertexAttribute.hpp"
#include "utils/accumulate.hpp"

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
    return accumulate(0, attributes, [](const GLsizei stride, const IVertexAttribute* attribute) {
        return stride + attribute->getSize();
    });
}

VertexLayout::Impl::Impl(Attributes& attributes)
    : attributes(attributes)
    , stride(calculateStride(this->attributes)) {}

} // namespace onux
