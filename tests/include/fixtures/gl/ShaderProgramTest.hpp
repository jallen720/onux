#pragma once

#include <memory>

#include "fixtures/gl/OnuxTest.hpp"
#include "graphics/ShaderSource.hpp"
#include "gl/ShaderObject.hpp"
#include "gl/ShaderProgram.hpp"
#include "utils/testShaderPath.hpp"

struct ShaderProgramTest : OnuxTest {
private:
    const onux::ShaderSource validSources[2] {
        { testShaderPath("valid.vert") },
        { testShaderPath("valid.frag") },
    };

protected:
    typedef std::unique_ptr<onux::ShaderObject> ShaderObjectPtr;
    typedef std::unique_ptr<onux::ShaderProgram> ShaderProgramPtr;

    ShaderObjectPtr validObjects[2] {
        ShaderObjectPtr(new onux::ShaderObject({
            &validSources[0]
        })),
        ShaderObjectPtr(new onux::ShaderObject({
            &validSources[1]
        })),
    };

    ShaderProgramPtr validShaderProgram =
        ShaderProgramPtr(new onux::ShaderProgram({
            validObjects[0].get(),
            validObjects[1].get(),
        }));

public:
    ShaderProgramTest() {}

    ShaderProgramTest(ShaderProgramTest&& original)
        : validObjects {
            std::move(original.validObjects[0]),
            std::move(original.validObjects[1]),
        }
        , validShaderProgram(
            std::move(original.validShaderProgram)
        ) {}
};
