#include "gl/utils/ValidValues.hpp"

#include <map>

#include "utils/contains.hpp"
#include "utils/values.hpp"

using std::map;

namespace onux {

struct ValidValues::Impl {
    const map<const GLenum, const ValueName> validValues;

    Impl(ValidValueList validValues);
};

ValidValues::ValidValues(ValidValueList validValues)
    : impl(new Impl(validValues)) {}

ValidValues::~ValidValues() {}

const bool ValidValues::contains(const GLenum value) const {
    return onux::contains(impl->validValues, value);
}

auto ValidValues::getName(const GLenum value) const -> ValueName {
    return impl->validValues.at(value);
}

auto ValidValues::getNames() const -> ValueNames {
    return values(impl->validValues);
}

// Implementation

ValidValues::Impl::Impl(ValidValueList validValues)
    : validValues(validValues) {}

} // namespace onux
