#include "resources/parsers/ShaderFile.hpp"

#include "utils/expectNoThrow.hpp"
#include "utils/assertEqualElements.hpp"
#include "utils/testShaderPath.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"
#include "exceptions/FileError.hpp"

using onux::ShaderFile;
using onux::EmptyStringArg;
using onux::InvalidArg;
using onux::FileError;

TEST(ShaderFileTest, validCreation) {
    expectNoThrow([] {
        const ShaderFile shaderFile(testShaderPath("valid"));
    });
}

TEST(ShaderFileTest, notAllRequiredTypes) {
    EXPECT_THROW(const ShaderFile shaderFile(testShaderPath("missingRequiredTypes")), FileError);
}

TEST(ShaderFileTest, emptyPath) {
    EXPECT_THROW(const ShaderFile shaderFile(""), EmptyStringArg);
}

TEST(ShaderFileTest, correctShaderSources) {
    const ShaderFile shaderFile(testShaderPath("multipleSources"));

    assertEqualElements(
        { "src0", "src1", "src2" },
        shaderFile.getSources("vert")
    );

    assertEqualElements(
        { "src3", "src4", "src5" },
        shaderFile.getSources("frag")
    );
}

TEST(ShaderFileTest, getSourcesEmptyType) {
    EXPECT_THROW(
        ShaderFile(testShaderPath("valid")).getSources(""),
        EmptyStringArg
    );
}

TEST(ShaderFileTest, getSourcesInvalidType) {
    EXPECT_THROW(
        ShaderFile(testShaderPath("valid")).getSources("invalid_type"),
        InvalidArg
    );
}

TEST(ShaderFileTest, parsingMissingDataDelimiter) {
    EXPECT_THROW(
        ShaderFile(testShaderPath("missingDataDelimiter")),
        FileError
    );
}

TEST(ShaderFileTest, parsingMultipleDataDelimiters) {
    EXPECT_THROW(
        ShaderFile(testShaderPath("multipleDataDelimiters")),
        FileError
    );
}

TEST(ShaderFileTest, parsingInvalidSourceType) {
    EXPECT_THROW(
        ShaderFile(testShaderPath("invalidSourceType")),
        InvalidArg
    );
}

TEST(ShaderFileTest, parsingNoSourcesForType) {
    EXPECT_THROW(
        ShaderFile(testShaderPath("noSourcesForType")),
        FileError
    );
}
