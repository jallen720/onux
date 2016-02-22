#include "resources/files/ShaderFile.hpp"

#include <string>
#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "tests/utils/expectNoThrow.hpp"
#include "tests/utils/validResourcePath.hpp"
#include "tests/utils/invalidResourcePath.hpp"
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
        ShaderFile::create(validResourcePath("shaders", "valid.yaml"));
    });
}

TEST(ShaderFileTest, emptyPath) {
    EXPECT_THROW(ShaderFile::create(""), EmptyStringArg);
}

TEST(ShaderFileTest, invalidPath) {
    EXPECT_THROW(
        ShaderFile::create(invalidResourcePath("shaders", "invalid_path.yaml")),
        BadFile
    );
}

TEST(ShaderFileTest, invalidTypeFormat) {
    EXPECT_THROW(
        ShaderFile::create(invalidResourcePath("shaders", "invalidTypeFormat.yaml")),
        FileError
    );
}

TEST(ShaderFileTest, invalidSourcePathsFormat) {
    EXPECT_THROW(
        ShaderFile::create(invalidResourcePath("shaders", "invalidSourcePathsFormat.yaml")),
        FileError
    );
}

TEST(ShaderFileTest, missingRequiredTypes) {
    EXPECT_THROW(
        ShaderFile::create(invalidResourcePath("shaders", "missingRequiredTypes.yaml")),
        FileError
    );
}
