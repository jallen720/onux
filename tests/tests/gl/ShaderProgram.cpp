#include "gl/ShaderProgram.hpp"

#include <glm/glm.hpp>

#include "fixtures/gl/ShaderProgramTest.hpp"
#include "gl/utils/getInt.hpp"
#include "exceptions/Error.hpp"
#include "exceptions/argErrors/ArgFailedRequirement.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"
#include "exceptions/argErrors/NullArg.hpp"
#include "utils/expectNoThrow.hpp"
#include "utils/expectGLError.hpp"

using glm::vec3;
using glm::vec4;
using glm::mat4;
using onux::ShaderProgram;
using onux::ShaderObject;
using onux::ShaderSource;
using onux::getInt;
using onux::Error;
using onux::ArgFailedRequirement;
using onux::EmptyStringArg;
using onux::NullArg;

TEST_F(ShaderProgramTest, validCreation) {
    expectNoThrow([&] {
        const ShaderProgram shaderProgram({
            validObjects[0].get(),
            validObjects[1].get(),
        });
    });
}

TEST_F(ShaderProgramTest, notAllRequiredTypes) {
    // A ShaderProgram requires atleast a vertex shader object and a fragment
    // shader object.
    EXPECT_THROW(
        const ShaderProgram shaderProgram({
            validObjects[0].get(),
        }),
        ArgFailedRequirement
    );
}

TEST_F(ShaderProgramTest, noMainInObject) {
    const ShaderSource noMainSource(testShaderPath("noMain.vert"));
    const ShaderObject noMainObject({ &noMainSource });

    EXPECT_THROW(
        const ShaderProgram shaderProgram({
            &noMainObject,
            validObjects[1].get(),
        }),
        Error
    );
}

TEST_F(ShaderProgramTest, use) {
    // Only after calling use() should a ShaderProgram be the current program.
    ASSERT_NE(getInt(GL_CURRENT_PROGRAM), validShaderProgram->getID());

    validShaderProgram->use();
    EXPECT_EQ(getInt(GL_CURRENT_PROGRAM), validShaderProgram->getID());
}

TEST_F(ShaderProgramTest, setValidUniform) {
    // A ShaderProgram must be the current program in order to set uniforms.
    validShaderProgram->use();

    expectNoThrow([&] {
        validShaderProgram->setUniform("testVec3", vec3());
        validShaderProgram->setUniform("testVec4", vec4());
        validShaderProgram->setUniform("testMat4", mat4());
        validShaderProgram->setUniform("testMat4", mat4(), GL_TRUE);
    });
}

TEST_F(ShaderProgramTest, setInvalidUniform) {
    EXPECT_THROW(validShaderProgram->setUniform("", 0), EmptyStringArg);
    EXPECT_THROW(validShaderProgram->setUniform(nullptr, 0), NullArg);
}

TEST_F(ShaderProgramTest, setUnusedUniform) {
    const ShaderSource unusedUniformSource(testShaderPath("unusedUniform.vert"));
    const ShaderObject unusedUniformObject({ &unusedUniformSource });

    const ShaderProgram shaderProgram({
        &unusedUniformObject,
        validObjects[1].get(),
    });

    // OpenGL optimizes out unused uniforms, so trying to set a uniform that is
    // unused will fail, as the uniform won't exist.
    EXPECT_THROW(
        shaderProgram.setUniform("unusedVec3", vec3()),
        Error
    );
}

TEST_F(ShaderProgramTest, setUniformNotCurrentProgram) {
    const ShaderProgram shaderProgram({
        validObjects[0].get(),
        validObjects[1].get(),
    });

    // Trying to set a uniform on a program that is not the current program will
    // generate a GL_INVALID_OPERATION error.
    expectGLError(GL_INVALID_OPERATION, [&shaderProgram] {
        shaderProgram.setUniform("testVec3", vec3());
    });
}
