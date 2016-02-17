#include "exceptions/validators/validateNotEmpty.hpp"

#include <cstring>

#include "exceptions/argErrors/EmptyStringArg.hpp"

using std::string;

namespace onux {

void validateNotEmpty(
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

void validateNotEmpty(
    const string& parameter,
    const string& function,
    const char*   arg
) {
    if (isEmpty(arg)) {
        throw EmptyStringArg(parameter, function);
    }
}

} // namespace onux
