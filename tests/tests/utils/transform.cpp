#include "utils/transform.hpp"

#include <map>

#include "utils/assertEqualElements.hpp"

using std::map;
using std::pair;
using onux::transform;

TEST(transformTest, test) {
    const map<const int, int> mappedNumbers {
        { 1, 0 },
        { 2, 3 },
        { 6, 5 },
    };

    assertEqualElements(
        { 1, 5, 11 },
        transform<int>(mappedNumbers, [](const pair<const int, int>& element) {
            return element.first + element.second;
        })
    );
}
