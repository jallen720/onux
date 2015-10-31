#pragma once

#include "OnuxTest.hpp"
#include "graphics/ShaderSource.hpp"
#include "gl/ShaderObject.hpp"
#include "testUtil.hpp"

struct ShaderProgramTest : OnuxTest {
private:
  const onux::ShaderSource validSources[2] {
    { testShaderPath("valid.vert") },
    { testShaderPath("valid.frag") },
  };

protected:
  const onux::ShaderObject validObjects[2] {
    { { &validSources[0] } },
    { { &validSources[1] } },
  };
};
