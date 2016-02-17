#include "resources/files/ShaderFile.hpp"

#include <string>
#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "tests/utils/expectNoThrow.hpp"
#include "tests/utils/testShaderPath.hpp"
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
        ShaderFile(testShaderPath("valid.yaml"));
    });
}

TEST(ShaderFileTest, emptyPath) {
    EXPECT_THROW(ShaderFile(""), EmptyStringArg);
}

TEST(ShaderFileTest, invalidPath) {
    EXPECT_THROW(ShaderFile(testShaderPath("invalid_path.yaml")), BadFile);
}

TEST(ShaderFileTest, invalidTypeFormat) {
    EXPECT_THROW(ShaderFile(testShaderPath("invalidTypeFormat.yaml")), FileError);
}

TEST(ShaderFileTest, invalidSourcePathsFormat) {
    EXPECT_THROW(ShaderFile(testShaderPath("invalidSourcePathsFormat.yaml")), FileError);
}

TEST(ShaderFileTest, missingRequiredTypes) {
    EXPECT_THROW(ShaderFile(testShaderPath("missingRequiredTypes.yaml")), FileError);
}
