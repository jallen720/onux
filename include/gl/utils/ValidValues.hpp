#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <utility>
#include <map>
#include <GL/glew.h>

namespace onux {

class ValidValues {
private:
  typedef std::string ValueName;
  typedef const std::vector<ValueName> ValueNames;
  typedef std::pair<const GLenum, const ValueName> ValidValue;
  typedef const std::initializer_list<ValidValue>& ValidValueList;

public:
  explicit ValidValues(ValidValueList validValues);
  const bool contains(const GLenum value) const;
  ValueName getName(const GLenum value) const;
  ValueNames getNames() const;

private:
  const std::map<const GLenum, const ValueName> m_validValues;
};

} // namespace onux

#define VALID_VALUE(VALUE) { VALUE, #VALUE }
