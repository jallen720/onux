#include "utils/ValidGLValues.hpp"

#include "utils/contains.hpp"
#include "utils/values.hpp"

using std::map;

namespace onux {

struct ValidGLValues::Impl {
    Values values;
};

ValidGLValues::ValidGLValues(Values& values)
    : impl(new Impl { values }) {}

ValidGLValues::~ValidGLValues() {}

const bool ValidGLValues::contains(const GLenum value) const {
    return onux::contains(impl->values, value);
}

auto ValidGLValues::getName(const GLenum value) const -> ValueName {
    return impl->values.at(value);
}

auto ValidGLValues::getNames() const -> ValueNames {
    return values(impl->values);
}

} // namespace onux
