#include "utils/split.hpp"

#include "utils/assertEqualElements.hpp"

using std::string;
using std::vector;
using std::equal;
using onux::split;

TEST(splitTest, successfulSplit) {
    assertEqualElements(
        { "this", "is", "a", "sentence!" },
        split("this is a sentence!", ' ')
    );
}

TEST(splitTest, emptyString) {
    assertEqualElements(vector<string>(), split("", ' '));
}

TEST(splitTest, emptyStringsAroundDelimiter) {
    EXPECT_EQ(2, split("=src1", '=').size());
    EXPECT_EQ(1, split("test=", '=').size());
    EXPECT_EQ(1, split("="    , '=').size());
}
