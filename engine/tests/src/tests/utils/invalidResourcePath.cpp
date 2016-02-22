#include "tests/utils/invalidResourcePath.hpp"

using std::string;

const string invalidResourcePath(const string& subDirectory, const string& name) {
    static const string INVALID_RESOURCES_DIRECTORY = "tests/resources/invalid/";
    static const string DIRECTORY_DELIMITER       = "/";

    return INVALID_RESOURCES_DIRECTORY + subDirectory + DIRECTORY_DELIMITER + name;
}
