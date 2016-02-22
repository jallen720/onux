#include "utils/removeSubString.hpp"

#include <gtest/gtest.h>

using std::string;
using onux::removeSubString;

TEST(removeSubStringTest, validSubString) {
    EXPECT_EQ("expected", removeSubString("sub-string expected", "sub-string "));
}

TEST(removeSubStringTest, invalidSubString) {
    EXPECT_EQ("expected", removeSubString("expected", "invalid"));
}

TEST(removeSubStringTest, emptySubString) {
    EXPECT_EQ("expected", removeSubString("expected", ""));
}

TEST(removeSubStringTest, multipleSubStrings) {
    EXPECT_EQ("expectedsub-string", removeSubString("sub-stringexpectedsub-string", "sub-string"));
}
