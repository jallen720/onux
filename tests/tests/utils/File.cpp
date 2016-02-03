#include "utils/File.hpp"

#include "utils/values.hpp"

#include <gtest/gtest.h>
#include <cstring>

#include "utils/expectNoThrow.hpp"
#include "utils/testShaderSourcePath.hpp"
#include "utils/testMiscFilePath.hpp"
#include "exceptions/Error.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using std::string;
using std::vector;
using onux::File;
using onux::Error;
using onux::EmptyStringArg;

TEST(FileTest, validCreation) {
    expectNoThrow([] {
        const File file(testShaderSourcePath("valid.vert"));
    });
}

TEST(FileTest, contentsMatch) {
    static const char* expectedResult =
        "#version 330 core\n\r"
        "\n\r"
        "layout (location = 0) in vec3 position;\n\r"
        "\n\r"
        "out vec4 vertColor;\n\r"
        "\n\r"
        "uniform vec3 testVec3;\n\r"
        "uniform mat4 testMat4;\n\r"
        "\n\r"
        "void main() {\n\r"
        "    gl_Position = testMat4 * vec4(position + testVec3, 1.0);\n\r"
        "    vertColor = gl_Position;\n\r"
        "}\n\r";

    EXPECT_TRUE(strcmp(
        expectedResult,
        File(testShaderSourcePath("valid.vert")).getContents().c_str()
    ));
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
        Error
    );
}

TEST(FileTest, emptyPath) {
    EXPECT_THROW(
        const File file(""),
        EmptyStringArg
    );
}
