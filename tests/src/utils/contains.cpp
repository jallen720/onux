#include "utils/contains.hpp"

#include <vector>
#include <map>
#include <gtest/gtest.h>

using std::vector;
using std::map;
using onux::contains;

TEST(containsTest, test) {
    const map<const int, int> mappedNumbers {
        { 1, 0 },
        { 2, 3 },
        { 6, 5 },
    };

    const vector<int> numbers { 1, 2, 3 };

    // Checks keys, not values (uses map::contains()).
    ASSERT_FALSE(contains(mappedNumbers, 3));
    ASSERT_TRUE(contains(mappedNumbers, 6));
    ASSERT_TRUE(contains(numbers, 1));
    ASSERT_FALSE(contains(numbers, 4));
}
