#include "utils/split.hpp"

#include <gtest/gtest.h>
#include <algorithm>

using std::string;
using std::vector;
using std::equal;
using onux::split;

TEST(splitTest, successfulSplit) {
    const vector<string> result = split("this is a sentence!", ' ');
    const vector<string> expectedResult { "this", "is", "a", "sentence!" };

    EXPECT_TRUE(equal(
        result.begin(),
        result.end(),
        expectedResult.begin()
    ));
}

TEST(splitTest, emptyString) {
    const vector<string> result = split("", ' ');
    const vector<string> expectedResult;

    EXPECT_TRUE(equal(
        result.begin(),
        result.end(),
        expectedResult.begin()
    ));
}
