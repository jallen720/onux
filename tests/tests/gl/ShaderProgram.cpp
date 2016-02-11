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

using std::vector;
using std::move;
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
        ShaderProgram { validObjects };
    });
}

TEST_F(ShaderProgramTest, notAllRequiredTypes) {
    ShaderObjects invalidObjects;
    invalidObjects.push_back(move(validObjects[0]));

    // A ShaderProgram requires atleast a vertex shader object and a fragment shader object.
    EXPECT_THROW(ShaderProgram { invalidObjects }, ArgFailedRequirement);
}

TEST_F(ShaderProgramTest, noMainInObject) {
    const ShaderSource noMainSource(testShaderSourcePath("noMain.vert"));
    ShaderObjects invalidObjects;
    invalidObjects.emplace_back(new ShaderObject({ &noMainSource }));
    invalidObjects.push_back(move(validObjects[1]));

    // If one of the sources is missing a main() function then ShaderProgram linking will fail.
    EXPECT_THROW(ShaderProgram { invalidObjects }, Error);
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
    const ShaderSource unusedUniformSource(testShaderSourcePath("unusedUniform.vert"));
    ShaderObjects invalidObjects;
    invalidObjects.emplace_back(new ShaderObject({ &unusedUniformSource }));
    invalidObjects.push_back(move(validObjects[1]));

    // OpenGL optimizes out unused uniforms, so trying to set a uniform that is unused will fail, as
    // the uniform won't exist.
    EXPECT_THROW(
        ShaderProgram { invalidObjects }.setUniform("unusedVec3", vec3()),
        Error
    );
}

TEST_F(ShaderProgramTest, setUniformNotCurrentProgram) {
    // Trying to set a uniform on a program that has not been made the current program (via
    // ShaderProgram::use()) will generate a GL_INVALID_OPERATION error.
    expectGLError(GL_INVALID_OPERATION, [&] {
        validShaderProgram->setUniform("testVec3", vec3());
    });
}
