#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <GL/glew.h>

namespace onux {

class ValidGLValues {
private:
    using ValueName  = std::string;
    using ValueNames = const std::vector<ValueName>;
    using Values     = const std::map<const GLenum, const ValueName>;

public:
    explicit ValidGLValues(Values& values);
    ~ValidGLValues();
    const bool contains(const GLenum value) const;
    ValueName getName(const GLenum value) const;
    ValueNames getNames() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
