#include "exceptions/messageBuilders/buildMustBe.hpp"

#include "utils/accumulate.hpp"

using std::string;
using std::vector;

namespace onux {

const string buildMustBe(const vector<string>& validArguments) {
    return accumulate<string>(
        "\n",
        validArguments,
        [](const string& mustBe, const string& validArgument) {
            return mustBe + "      " + validArgument + ",\n";
        }
    );
}

} // namespace onux
