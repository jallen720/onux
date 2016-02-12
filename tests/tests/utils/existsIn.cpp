#include "utils/existsIn.hpp"

#include <vector>
#include <map>
#include <gtest/gtest.h>

using std::vector;
using std::map;
using std::pair;
using onux::existsIn;

TEST(existsInTest, test) {
    const map<const int, int> mappedNumbers {
        { 1, 0 },
        { 2, 3 },
        { 6, 5 },
    };

    const vector<int> numbers { 1, 2, 3 };

    ASSERT_TRUE(existsIn(numbers, [](const int number) {
        return number > 2;
    }));

    ASSERT_FALSE(existsIn(numbers, [](const int number) {
        return number < 0;
    }));

    ASSERT_TRUE(existsIn(mappedNumbers, [](const pair<const int, int>& element) {
        return element.first == 2 &&
               element.second == 3;
    }));

    ASSERT_FALSE(existsIn(mappedNumbers, [](const pair<const int, int>& element) {
        return element.second == 6;
    }));
}
