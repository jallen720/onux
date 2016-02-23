#pragma once

#include <memory>

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "resources/ShaderSource.hpp"
#include "resources/Resources.hpp"
#include "gl/ShaderObject.hpp"
#include "gl/ShaderProgram.hpp"

struct ShaderProgramTest : OnuxTest {
private:
    const onux::Resources<onux::ShaderSource> validSources {
        "tests/resources/valid/shaderSources"
    };

protected:
    using ShaderProgramPtr = std::unique_ptr<onux::ShaderProgram>;

    onux::ShaderProgram::Objects validObjects = [&]() {
        onux::ShaderProgram::Objects validObjects;
        validObjects.emplace_back(new onux::ShaderObject({ validSources["valid.vert"] }));
        validObjects.emplace_back(new onux::ShaderObject({ validSources["valid.frag"] }));
        return validObjects;
    }();

    ShaderProgramPtr validShaderProgram { new onux::ShaderProgram(validObjects) };

public:
    ShaderProgramTest() {}
};
