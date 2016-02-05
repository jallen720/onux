#include "resources/parsers/ShaderFile.hpp"

#include <algorithm>

#include "utils/File.hpp"
#include "utils/split.hpp"
#include "utils/existsIn.hpp"
#include "utils/contains.hpp"
#include "utils/keys.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"
#include "exceptions/FileError.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"

using std::string;
using std::vector;
using std::map;
using std::count;

namespace onux {

typedef std::map<const std::string, ShaderFile::SourceList> SourceLists;
typedef const vector<string>& Data;

struct ShaderFile::Impl {
    SourceLists sourceLists;

    Impl(const string& path);
    void loadSourceLists(const string& path);
    void parseData(Data data, const string& path);
};

static const string getValidPath(const string& path) {
    static const string SHADER_FILE_EXTENSION = "shader";

    validateNotEmpty("path", "ShaderFile::ShaderFile", path);
    return path + "." + SHADER_FILE_EXTENSION;
}

ShaderFile::ShaderFile(const string& path)
    : impl(new Impl(getValidPath(path))) {}

ShaderFile::~ShaderFile() {}

static const bool isType(const SourceLists& sourceLists, const string& type) {
    return contains(keys(sourceLists), type);
}

static void validateIsType(
    const SourceLists& sourceLists,
    const string&      type,
    const string&      function
) {
    if (!isType(sourceLists, type)) {
        throw InvalidArg("type", function, keys(sourceLists));
    }
}

auto ShaderFile::getSources(const string& type) const -> const SourceList& {
    validateNotEmpty("type", "ShaderFile::getSources", type);
    validateIsType(impl->sourceLists, type, "ShaderFile::getSources");
    return impl->sourceLists.at(type);
}

// Implementation

static const bool hasRequiredTypes(const SourceLists& sourceLists) {
    static const vector<string> REQUIRED_TYPES { "vert", "frag" };

    return !existsIn(REQUIRED_TYPES, [&](const string& requiredSourceType) {
        return sourceLists.at(requiredSourceType).size() == 0;
    });
}

static void validateHasRequiredTypes(const SourceLists& sourceLists, const string& path) {
    if (!hasRequiredTypes(sourceLists)) {
        throw FileError(
            path,
            "ShaderFile::Impl::Impl",
            "must have atleast 1 vertex and 1 fragment shader source"
        );
    }
}

ShaderFile::Impl::Impl(const string& path)
    : sourceLists({
        { "vert", SourceList() },
        { "tesc", SourceList() },
        { "tese", SourceList() },
        { "geom", SourceList() },
        { "frag", SourceList() },
        { "comp", SourceList() },
    }) {
    loadSourceLists(path);
    validateHasRequiredTypes(sourceLists, path);
}

static const auto DATA_DELIMITER = '=';

static const bool hasOneDataDelimiter(const string& line) {
    return count(line.begin(), line.end(), DATA_DELIMITER) == 1;
}

static void validateHasOneDataDelimiter(const string& line, const string& path) {
    if (!hasOneDataDelimiter(line)) {
        throw FileError(
            path,
            "Shaderfile::Impl::loadSourceLists",
            "line: \"" + line + "\" must have one \"=\""
        );
    }
}

void ShaderFile::Impl::loadSourceLists(const string& path) {
    File(path).forEachLine([&](const string& line) {
        validateHasOneDataDelimiter(line, path);
        parseData(split(line, DATA_DELIMITER), path);
    });
}

static const bool hasValues(Data data) {
    // The data vector should have 2 strings: a key string and values string.
    static const auto SIZE_OF_DATA_WITH_VALUES = 2u;

    return data.size() == SIZE_OF_DATA_WITH_VALUES;
}

static const auto DATA_KEY_INDEX = 0u;

static void validateHasValues(Data data, const string& path) {
    if (!hasValues(data)) {
        throw FileError(
            path,
            "ShaderFile::Impl::parseData",
            "no sources provided for type: " + data[DATA_KEY_INDEX]
        );
    }
}

void ShaderFile::Impl::parseData(Data data, const string& path) {
    static const auto VALUE_DELIMITER = ' ';
    static const auto DATA_VALUES_INDEX = 1u;

    const string& key = data[DATA_KEY_INDEX];
    validateIsType(sourceLists, key, "ShaderFile::Impl::parseData");
    validateHasValues(data, path);
    sourceLists[key] = split(data[DATA_VALUES_INDEX], VALUE_DELIMITER);
}

} // namespace onux
