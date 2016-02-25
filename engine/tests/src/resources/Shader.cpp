#include "resources/Shader.hpp"

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
using onux::Shader;
using onux::EmptyStringArg;
using onux::FileError;

TEST(ShaderTest, validCreation) {
    expectNoThrow([] {
        Shader::create(validResourcePath("shaders", "valid.yaml"));
    });
}

TEST(ShaderTest, emptyPath) {
    EXPECT_THROW(Shader::create(""), EmptyStringArg);
}

TEST(ShaderTest, invalidPath) {
    EXPECT_THROW(
        Shader::create(invalidResourcePath("shaders", "invalid_path.yaml")),
        BadFile
    );
}

TEST(ShaderTest, invalidTypeFormat) {
    EXPECT_THROW(
        Shader::create(invalidResourcePath("shaders", "invalidTypeFormat.yaml")),
        FileError
    );
}

TEST(ShaderTest, invalidSourcePathsFormat) {
    EXPECT_THROW(
        Shader::create(invalidResourcePath("shaders", "invalidSourcePathsFormat.yaml")),
        FileError
    );
}

TEST(ShaderTest, missingRequiredTypes) {
    EXPECT_THROW(
        Shader::create(invalidResourcePath("shaders", "missingRequiredTypes.yaml")),
        FileError
    );
}
