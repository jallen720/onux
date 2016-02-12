#pragma once

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "resources/containers/ShaderSources.hpp"

struct ShaderTest : OnuxTest {
protected:
    const onux::ShaderSources shaderSources;
};
