#pragma once

#include "gl/utils/ObjectInfo.hpp"

namespace onux {

class ShaderObjectInfo : public ObjectInfo {
public:
    using ObjectInfo::ObjectInfo;

protected:
    virtual void validateParameter(const GLenum parameter) const override;
};

} // namespace onux
