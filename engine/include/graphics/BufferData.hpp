#pragma once

#include <vector>
#include <initializer_list>

#include "gl/interfaces/IBufferData.hpp"

#include "MACROS/ONUX_MOVE_ONLY.hpp"

namespace onux {

template<typename T>
class BufferData : public IBufferData {
public:
    BufferData() = default;
    explicit BufferData(const std::initializer_list<T>& data);
    ONUX_MOVE_ONLY(BufferData)
    void add(const T& element);

    // IBufferData
    virtual const size_t getCount() const override;
    virtual const GLsizei getSize() const override;
    virtual const GLvoid* getPointer() const override;

private:
    std::vector<T> m_data;
};

} // namespace onux

#include "graphics/BufferData.ipp"
