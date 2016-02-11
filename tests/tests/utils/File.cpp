#include "utils/File.hpp"

#include <gtest/gtest.h>

#include "utils/expectNoThrow.hpp"
#include "utils/testMiscFilePath.hpp"
#include "exceptions/FileError.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using std::string;
using std::vector;
using onux::File;
using onux::FileError;
using onux::EmptyStringArg;

TEST(FileTest, validCreation) {
    expectNoThrow([] {
        File(testMiscFilePath("test.txt"));
    });
}

TEST(FileTest, invalidFile) {
    EXPECT_THROW(File("does_not_exist"), FileError);
}

TEST(FileTest, emptyPath) {
    EXPECT_THROW(File(""), EmptyStringArg);
}

TEST(FileTest, contentsMatch) {
    static const string expectedResult =
        "line1\n"
        "line2\n"
        "line3\n";

    EXPECT_EQ(expectedResult, File(testMiscFilePath("test.txt")).getContents());
}

TEST(FileTest, linesMatch) {
    static const vector<string> expectedResult {
        "line1",
        "line2",
        "line3",
    };

    vector<string> result;

    File(testMiscFilePath("test.txt")).forEachLine([&](const string& line) {
        result.push_back(line);
    });

    for (auto i = 0u; i < result.size(); i++) {
        EXPECT_EQ(expectedResult[i], result[i]);
    }
}
