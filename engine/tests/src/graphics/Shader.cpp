#include "graphics/Shader.hpp"

#include "tests/fixtures/graphics/ShaderTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "tests/utils/validResourcePath.hpp"
#include "resources/files/ShaderFile.hpp"

using onux::Shader;
using onux::ShaderFile;

TEST_F(ShaderTest, validCreation) {
    const ShaderFile::Ptr validShaderFile =
        ShaderFile::create(validResourcePath("shaders", "valid.yaml"));

    expectNoThrow([&] {
        Shader::create(validShaderFile.get(), validShaderSources);
    });
}
