#include "tests/utils/testMiscFilePath.hpp"

using std::string;

const string testMiscFilePath(const string& name) {
    static const string TEST_MISC_FILE_DIRECTORY = "tests/resources/miscFiles/";
    return TEST_MISC_FILE_DIRECTORY + name;
}
