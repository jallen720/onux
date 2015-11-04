#pragma once

#include "gl/interfaces/IVertexAttribute.hpp"

namespace onux {

template<typename T>
class VertexAttribute : public IVertexAttribute {
public:
  VertexAttribute(
    const GLint     elementCount,
    const GLenum    type,
    const GLboolean isNormalized,
    const GLvoid*   offset
  );

  // IVertexAttribute
  const GLint getElementCount() const override;
  const GLenum getType() const override;
  const GLboolean getIsNormalized() const override;
  const GLvoid* getOffset() const override;
  const GLsizei getSize() const override;

private:
  const GLint     m_elementCount;
  const GLenum    m_type;
  const GLboolean m_isNormalized;
  const GLvoid*   m_offset;
};

} // namespace onux

#include "graphics/VertexAttribute.ipp"
