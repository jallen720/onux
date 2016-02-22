#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "resources/Resources.hpp"
#include "graphics/ShaderSource.hpp"

struct ShaderTest : OnuxTest {
protected:
    const onux::Resources<onux::ShaderSource> validShaderSources {
        "tests/resources/valid/shaderSources"
    };
};
