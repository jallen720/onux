#pragma once

#include <memory>

#include "tests/fixtures/gl/OnuxTest.hpp"
#include "resources/ShaderSource.hpp"
#include "resources/loadResources.hpp"
#include "gl/ShaderObject.hpp"
#include "gl/ShaderProgram.hpp"
#include "utils/UniqueMap.hpp"

struct ShaderProgramTest : OnuxTest {
private:
    const onux::UniqueMap<onux::ShaderSource> validShaderSources =
        onux::loadResources<onux::ShaderSource>("tests/resources/valid/shaderSources");

protected:
    onux::ShaderProgram::Objects validObjects = [&]() {
        onux::ShaderProgram::Objects validObjects;
        validObjects.push_back(onux::ShaderObject::create({ validShaderSources["valid.vert"] }));
        validObjects.push_back(onux::ShaderObject::create({ validShaderSources["valid.frag"] }));
        return validObjects;
    }();

    onux::ShaderProgram::Ptr validShaderProgram =
        onux::ShaderProgram::create(validObjects);
};
