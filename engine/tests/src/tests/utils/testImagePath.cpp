#include "tests/utils/testImagePath.hpp"

using std::string;

const string testImagePath(const string& name) {
    static const string TEST_IMAGES_DIRECTORY  = "tests/resources/images/";
    return TEST_IMAGES_DIRECTORY + name;
}
