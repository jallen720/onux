#include "resources/Shader.hpp"

#include <string>
#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "fixtures/resources/ShaderTest.hpp"
#include "utils/expectNoThrow.hpp"
#include "utils/testShaderPath.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"
#include "exceptions/FileError.hpp"

using std::string;
using YAML::BadFile;
using onux::Shader;
using onux::EmptyStringArg;
using onux::FileError;

TEST_F(ShaderTest, validCreation) {
    expectNoThrow([&] {
        const Shader shader("resources/shaders/diffuse", shaderSources);
    });
}

TEST_F(ShaderTest, emptyPath) {
    EXPECT_THROW(
        const Shader shader("", shaderSources),
        EmptyStringArg
    );
}

TEST_F(ShaderTest, invalidPath) {
    EXPECT_THROW(
        const Shader shader(testShaderPath("invalid_path"), shaderSources),
        BadFile
    );
}

TEST_F(ShaderTest, invalidTypeFormat) {
    EXPECT_THROW(
        const Shader shader(testShaderPath("invalidTypeFormat"), shaderSources),
        FileError
    );
}

TEST_F(ShaderTest, invalidSourcePathsFormat) {
    const string shaderPaths[] {
        testShaderPath("invalidSourcePathsFormat0"),
        testShaderPath("invalidSourcePathsFormat1"),
    };

    for (auto& shaderPath : shaderPaths) {
        EXPECT_THROW(
            const Shader shader(shaderPath, shaderSources),
            FileError
        );
    }
}

TEST_F(ShaderTest, invalidType) {
    EXPECT_THROW(
        const Shader shader(testShaderPath("invalidType"), shaderSources),
        FileError
    );
}

TEST_F(ShaderTest, emptySourcePaths) {
    EXPECT_THROW(
        const Shader shader(testShaderPath("emptySourcePaths"), shaderSources),
        FileError
    );
}

TEST_F(ShaderTest, missingRequiredTypes) {
    EXPECT_THROW(
        const Shader shader(testShaderPath("missingRequiredTypes"), shaderSources),
        FileError
    );
}
