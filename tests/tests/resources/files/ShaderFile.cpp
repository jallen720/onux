#include "resources/files/ShaderFile.hpp"

#include <string>
#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "utils/expectNoThrow.hpp"
#include "utils/testShaderPath.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"
#include "exceptions/FileError.hpp"

using std::string;
using YAML::BadFile;
using YAML::BadConversion;
using onux::ShaderFile;
using onux::EmptyStringArg;
using onux::FileError;

TEST(ShaderFileTest, validCreation) {
    expectNoThrow([] {
        const ShaderFile shaderFile(testShaderPath("valid.yaml"));
    });
}

TEST(ShaderFileTest, emptyPath) {
    EXPECT_THROW(
        const ShaderFile shaderFile(""),
        EmptyStringArg
    );
}

TEST(ShaderFileTest, invalidPath) {
    EXPECT_THROW(
        const ShaderFile shaderFile("invalid_path.yaml"),
        BadFile
    );
}

TEST(ShaderFileTest, invalidTypeFormat) {
    EXPECT_THROW(
        const ShaderFile shaderFile(testShaderPath("invalidTypeFormat.yaml")),
        FileError
    );
}

TEST(ShaderFileTest, invalidSourcePathsFormat) {
    EXPECT_THROW(
        const ShaderFile shaderFile(testShaderPath("invalidSourcePathsFormat.yaml")),
        FileError
    );
}

TEST(ShaderFileTest, missingRequiredTypes) {
    EXPECT_THROW(
        const ShaderFile shaderFile(testShaderPath("missingRequiredTypes.yaml")),
        FileError
    );
}
