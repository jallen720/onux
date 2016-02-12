#include "tests/utils/testShaderPath.hpp"

using std::string;

const string testShaderPath(const string& name) {
    static const string TEST_SHADER_DIRECTORY = "tests/resources/shaders/";
    return TEST_SHADER_DIRECTORY + name;
}
