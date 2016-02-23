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
        validObjects.push_back(onux::ShaderObject::create({ validSources["valid.vert"] }));
        validObjects.push_back(onux::ShaderObject::create({ validSources["valid.frag"] }));
        return validObjects;
    }();

    ShaderProgramPtr validShaderProgram { new onux::ShaderProgram(validObjects) };
};
