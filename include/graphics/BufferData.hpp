#pragma once

#include <vector>

#include "gl/IBufferData.hpp"

namespace onux {

template<typename T>
class BufferData : public IBufferData {
public:
  void add(T data);
  const size_t getCount() const;

  // IBufferData
  const GLsizei getSize() const override;
  const GLvoid* getPointer() const override;

private:
  std::vector<T> m_data;
};

} // namespace onux

#include "graphics/BufferData.ipp"
