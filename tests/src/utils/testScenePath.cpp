#include "utils/testScenePath.hpp"

using std::string;

const string testScenePath(const string& name) {
    static const string TEST_MODELS_DIRECTORY  = "tests/resources/scenes/";
    return TEST_MODELS_DIRECTORY + name;
}
