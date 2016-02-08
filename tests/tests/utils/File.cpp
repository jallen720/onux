#include "utils/File.hpp"

#include <gtest/gtest.h>

#include "utils/expectNoThrow.hpp"
#include "utils/testShaderSourcePath.hpp"
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
        const File file(testShaderSourcePath("valid.vert"));
    });
}

TEST(FileTest, contentsMatch) {
    static const string expectedResult =
        "#version 330 core\n"
        "\n"
        "layout (location = 0) in vec3 position;\n"
        "\n"
        "out vec4 vertColor;\n"
        "\n"
        "uniform vec3 testVec3;\n"
        "uniform mat4 testMat4;\n"
        "\n"
        "void main() {\n"
        "    gl_Position = testMat4 * vec4(position + testVec3, 1.0);\n"
        "    vertColor = gl_Position;\n"
        "}\n";

    EXPECT_EQ(
        expectedResult,
        File(testShaderSourcePath("valid.vert")).getContents()
    );
}

TEST(FileTest, linesMatch) {
    const vector<string> expectedResult {
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

TEST(FileTest, invalidFile) {
    EXPECT_THROW(
        const File file("does_not_exist"),
        FileError
    );
}

TEST(FileTest, emptyPath) {
    EXPECT_THROW(
        const File file(""),
        EmptyStringArg
    );
}
