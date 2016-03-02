#pragma once

#include <memory>

#include "gl/GLData.hpp"

namespace onux {

struct IVertexData;

class VertexArray : public GLData {
public:
    explicit VertexArray(const IVertexData& vertexData);
    ~VertexArray();
    void bind() const;
    const size_t getIndexCount() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
