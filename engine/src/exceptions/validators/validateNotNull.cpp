#include "exceptions/validators/validateNotNull.hpp"

#include "exceptions/argErrors/NullArg.hpp"

using std::string;

namespace onux {

void validateNotNull(
    const string& parameter,
    const string& function,
    const void*   arg
) {
    if (arg == nullptr) {
        throw NullArg(parameter, function);
    }
}

} // namespace onux
