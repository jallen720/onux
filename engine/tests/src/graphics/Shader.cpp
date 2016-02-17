#include "graphics/Shader.hpp"

#include "tests/fixtures/graphics/ShaderTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "resources/files/ShaderFile.hpp"

using onux::Shader;
using onux::ShaderFile;

TEST_F(ShaderTest, validCreation) {
    expectNoThrow([&] {
        Shader(ShaderFile("resources/shaders/diffuse.yaml"), shaderSources);
    });
}
