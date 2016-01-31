#include "gl/utils/ValidValues.hpp"

#include "utils/contains.hpp"
#include "utils/values.hpp"

using std::map;

namespace onux {

struct ValidValues::Impl {
    Values values;
};

ValidValues::ValidValues(Values& values)
    : impl(new Impl { values }) {}

ValidValues::~ValidValues() {}

const bool ValidValues::contains(const GLenum value) const {
    return onux::contains(impl->values, value);
}

auto ValidValues::getName(const GLenum value) const -> ValueName {
    return impl->values.at(value);
}

auto ValidValues::getNames() const -> ValueNames {
    return values(impl->values);
}

} // namespace onux
