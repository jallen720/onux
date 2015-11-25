#pragma once

#include "fixtures/gl/OnuxTest.hpp"
#include "graphics/ShaderSource.hpp"
#include "gl/ShaderObject.hpp"
#include "utils/testShaderPath.hpp"

struct ShaderProgramTest : OnuxTest {
private:
    const onux::ShaderSource validSources[2] {
        { testShaderPath("valid.vert") },
        { testShaderPath("valid.frag") },
    };

protected:
    const onux::ShaderObject validObjects[2] {
        onux::ShaderObject({
            &validSources[0]
        }),
        onux::ShaderObject({
            &validSources[1]
        }),
    };
};
