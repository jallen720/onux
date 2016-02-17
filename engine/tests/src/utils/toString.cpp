#include "utils/toString.hpp"

#include <gtest/gtest.h>

using onux::toString;

TEST(toStringTest, test) {
    ASSERT_EQ(toString(1)   , "1");
    ASSERT_EQ(toString(1l)  , "1");
    ASSERT_EQ(toString(1ll) , "1");
    ASSERT_EQ(toString(1u)  , "1");
    ASSERT_EQ(toString(1ul) , "1");
    ASSERT_EQ(toString(1ull), "1");
    ASSERT_EQ(toString(1.0f), "1.000000");
    ASSERT_EQ(toString(1.0) , "1.000000");
    ASSERT_EQ(toString(1.0l), "1.000000");
}
