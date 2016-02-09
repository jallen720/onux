#pragma once

#include "fixtures/gl/OnuxTest.hpp"
#include "resources/ResourceManager.hpp"
#include "resources/containers/ShaderSources.hpp"

struct ShaderTest : OnuxTest {
private:
    const onux::ResourceManager resourceManager;

protected:
    const onux::ShaderSources& shaderSources = resourceManager.getShaderSources();
};
