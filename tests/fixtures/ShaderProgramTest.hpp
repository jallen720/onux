#pragma once

#include "OnuxTest.hpp"
#include "ShaderSource.hpp"
#include "ShaderObject.hpp"
#include "../testUtil.hpp"

class ShaderProgramTest : public OnuxTest {
  const ShaderSource validSources[2] {
    { testShaderPath("valid.vert") },
    { testShaderPath("valid.frag") },
  };

public:
  const ShaderObject validObjects[2] {
    {{ &validSources[0] }},
    {{ &validSources[1] }},
  };
};
