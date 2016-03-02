#pragma once

namespace onux {

struct IBufferData;
struct IVertexLayout;

struct IVertexData {
    virtual ~IVertexData() {}
    virtual const IBufferData& getVertexes() const = 0;
    virtual const IBufferData& getIndexes() const = 0;
    virtual const IVertexLayout& getLayout() const = 0;
};

} // namespace onux
