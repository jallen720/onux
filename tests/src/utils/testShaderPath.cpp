#include "utils/testShaderPath.hpp"

using std::string;

const string testShaderPath(const string& name) {
    static const string TEST_SHADERS_DIRECTORY = "tests/resources/shaders/";
    return TEST_SHADERS_DIRECTORY + name;
}
