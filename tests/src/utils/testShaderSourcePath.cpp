#include "utils/testShaderSourcePath.hpp"

using std::string;

const string testShaderSourcePath(const string& name) {
    static const string TEST_SHADER_SOURCE_DIRECTORY = "tests/resources/shaderSources/";
    return TEST_SHADER_SOURCE_DIRECTORY + name;
}
