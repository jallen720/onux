namespace onux {

template<typename T>
void BufferData<T>::add(T data) {
  m_data.push_back(data);
}

template<typename T>
const size_t BufferData<T>::getCount() const {
  return m_data.size();
}

template<typename T>
const GLsizei BufferData<T>::getSize() const {
  return sizeof(T) * getCount();
}

template<typename T>
const GLvoid* BufferData<T>::getPointer() const {
  return &m_data[0];
}

} // namespace onux
