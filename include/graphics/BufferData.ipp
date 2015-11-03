namespace onux {

template<typename T>
BufferData<T>::BufferData() {}

template<typename T>
BufferData<T>::BufferData(const std::initializer_list<T>& data)
  : m_data(data) {}

template<typename T>
void BufferData<T>::add(T element) {
  m_data.push_back(element);
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
