#include "tests/utils/validResourcePath.hpp"

using std::string;

const string validResourcePath(const string& subDirectory, const string& name) {
    static const string VALID_RESOURCES_DIRECTORY = "tests/resources/valid/";
    static const string DIRECTORY_DELIMITER       = "/";

    return VALID_RESOURCES_DIRECTORY + subDirectory + DIRECTORY_DELIMITER + name;
}
