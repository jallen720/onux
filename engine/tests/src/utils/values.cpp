#include "utils/values.hpp"

#include "tests/utils/assertEqualElements.hpp"

using onux::values;

TEST(valuesTest, test) {
    assertEqualElements(
        { 0, 3, 5 },
        values<int, int>({
            { 1, 0 },
            { 2, 3 },
            { 6, 5 },
        })
    );
}
