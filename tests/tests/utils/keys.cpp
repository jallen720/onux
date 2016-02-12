#include "utils/keys.hpp"

#include "utils/assertEqualElements.hpp"

using onux::keys;

TEST(keysTest, test) {
    assertEqualElements(
        { 1, 2, 6 },
        keys<int, int>({
            { 1, 0 },
            { 2, 3 },
            { 6, 5 },
        })
    );
}
