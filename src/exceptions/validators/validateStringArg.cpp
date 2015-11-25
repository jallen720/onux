#include "exceptions/validators/validateStringArg.hpp"

#include <cstring>

#include "exceptions/argErrors/EmptyStringArg.hpp"
#include "exceptions/argErrors/NullArg.hpp"

using std::string;

namespace onux {

void validateStringArg(
    const string& parameter,
    const string& function,
    const string& arg
) {
    if (arg.empty()) {
        throw EmptyStringArg(parameter, function);
    }
}

static bool isEmpty(const char* arg) {
    return strcmp(arg, "") == 0;
}

void validateStringArg(
    const string& parameter,
    const string& function,
    const char*   arg
) {
    if (arg == nullptr) {
        throw NullArg(parameter, function);
    }
    else if (isEmpty(arg)) {
        throw EmptyStringArg(parameter, function);
    }
}

} // namespace onux
