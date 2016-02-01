#include "utils/testModelPath.hpp"

using std::string;

const string testModelPath(const string& name) {
    static const string TEST_MODELS_DIRECTORY  = "tests/resources/models/";
    return TEST_MODELS_DIRECTORY + name;
}
