namespace onux {

template<typename T>
VertexAttribute<T>::VertexAttribute(
  const GLint     elementCount,
  const GLenum    type,
  const GLboolean isNormalized,
  const GLvoid*   offset
) : m_elementCount(elementCount)
  , m_type(type)
  , m_isNormalized(isNormalized)
  , m_offset(offset) {}

template<typename T>
const GLint VertexAttribute<T>::getElementCount() const {
  return m_elementCount;
}

template<typename T>
const GLenum VertexAttribute<T>::getType() const {
  return m_type;
}

template<typename T>
const GLboolean VertexAttribute<T>::getIsNormalized() const {
  return m_isNormalized;
}

template<typename T>
const GLvoid* VertexAttribute<T>::getOffset() const {
  return m_offset;
}

template<typename T>
const GLsizei VertexAttribute<T>::getSize() const {
  return sizeof(T);
}

} // namespace onux
