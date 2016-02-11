#include "graphics/Shader.hpp"

#include "fixtures/graphics/ShaderTest.hpp"
#include "utils/expectNoThrow.hpp"
#include "resources/files/ShaderFile.hpp"

using onux::Shader;
using onux::ShaderFile;

TEST_F(ShaderTest, validCreation) {
    expectNoThrow([&] {
        const Shader shader(
            ShaderFile("resources/shaders/diffuse.yaml"),
            shaderSources
        );
    });
}
