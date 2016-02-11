#pragma once

#include <memory>

#include "fixtures/gl/OnuxTest.hpp"
#include "graphics/ShaderSource.hpp"
#include "gl/ShaderObject.hpp"
#include "gl/ShaderProgram.hpp"
#include "utils/testShaderSourcePath.hpp"

struct ShaderProgramTest : OnuxTest {
private:
    const onux::ShaderSource validSources[2] {
        { testShaderSourcePath("valid.vert") },
        { testShaderSourcePath("valid.frag") },
    };

protected:
    using ShaderObjects = std::vector<onux::ShaderObject::Ptr>;
    using ShaderProgramPtr = std::unique_ptr<onux::ShaderProgram>;

    ShaderObjects validObjects = [&]() {
        ShaderObjects validObjects;
        validObjects.emplace_back(new onux::ShaderObject({ &validSources[0] }));
        validObjects.emplace_back(new onux::ShaderObject({ &validSources[1] }));
        return validObjects;
    }();

    ShaderProgramPtr validShaderProgram { new onux::ShaderProgram(validObjects) };

public:
    ShaderProgramTest() {}
};
