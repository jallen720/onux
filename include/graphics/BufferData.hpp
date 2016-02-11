#pragma once

#include <vector>
#include <initializer_list>

#include "gl/interfaces/IBufferData.hpp"

#include "MACROS/ONUX_NON_COPYABLE.hpp"

namespace onux {

template<typename T>
class BufferData : public IBufferData {
public:
    BufferData();
    explicit BufferData(const std::initializer_list<T>& data);
    ONUX_NON_COPYABLE(BufferData)
    void add(const T& element);
    const size_t getCount() const;

    // IBufferData
    virtual const GLsizei getSize() const override;
    virtual const GLvoid* getPointer() const override;

private:
    std::vector<T> m_data;
};

} // namespace onux

#include "graphics/BufferData.ipp"
