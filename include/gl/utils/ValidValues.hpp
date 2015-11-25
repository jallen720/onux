#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <GL/glew.h>

namespace onux {

class ValidValues {
private:
    typedef std::string ValueName;
    typedef const std::vector<ValueName> ValueNames;
    typedef const std::map<const GLenum, const ValueName> Values;

public:
    explicit ValidValues(Values& values);
    ~ValidValues();
    const bool contains(const GLenum value) const;
    ValueName getName(const GLenum value) const;
    ValueNames getNames() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux

#define VALID_VALUE(VALUE) { VALUE, #VALUE }
