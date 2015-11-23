#include "gl/utils/ValidValues.hpp"

#include "utils/values.hpp"

namespace onux {

ValidValues::ValidValues(ValidValueList validValues)
  : m_validValues(validValues) {}

const bool ValidValues::contains(const GLenum value) const {
  return m_validValues.find(value) != m_validValues.end();
}

auto ValidValues::getName(const GLenum value) const -> ValueName {
  return m_validValues.at(value);
}

auto ValidValues::getNames() const -> ValueNames {
  return values(m_validValues);
}

} // namespace onux
