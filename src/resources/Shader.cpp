#include "resources/Shader.hpp"

#include <vector>
#include <map>
#include <memory>
#include <yaml-cpp/yaml.h>

#include "utils/contains.hpp"
#include "utils/existsIn.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"
#include "exceptions/FileError.hpp"
#include "gl/ShaderProgram.hpp"
#include "gl/ShaderObject.hpp"
#include "resources/containers/ShaderSources.hpp"

using std::string;
using std::vector;
using std::pair;
using std::unique_ptr;
using std::move;
using YAML::Node;
using YAML::LoadFile;
using YAML::BadConversion;

namespace onux {

typedef unique_ptr<const ShaderProgram> ShaderProgramPtr;

struct Shader::Impl {
    const ShaderProgramPtr shaderProgram;

    explicit Impl(const string& path, const ShaderSources& shaderSources);
    explicit Impl(const Node& data, const ShaderSources& shaderSources);
};

static const string getValidPath(const string& path) {
    static const string SHADER_FILE_EXTENSION = "yaml";

    validateNotEmpty("path", "ShaderFile::ShaderFile", path);
    return path + "." + SHADER_FILE_EXTENSION;
}

Shader::Shader(const string& path, const ShaderSources& shaderSources)
    : impl(new Impl(getValidPath(path), shaderSources)) {}

Shader::~Shader() {}

const ShaderProgram& Shader::getProgram() const {
    return *impl->shaderProgram;
}

// Implementation

typedef const pair<const Node&, const Node&>& Data;

static const string getType(Data data) {
    return data.first.as<string>();
}

static const vector<string> getSourcePaths(Data data) {
    return data.second.as<vector<string>>();
}

static const bool isValidType(const string& type) {
    static const vector<string> VALID_TYPES {
        "vert",
        "tesc",
        "tese",
        "geom",
        "frag",
        "comp",
    };

    return contains(VALID_TYPES, type);
}

static void validateIsValidType(const string& type, const string& path) {
    if (!isValidType(type)) {
        throw FileError(
            path,
            "Shader::Impl::Impl",
            "has and invalid type: \"" + type + "\""
        );
    }
}

static const bool hasSourcePaths(const vector<string>& sourcePaths) {
    return sourcePaths.size() > 0;
}

static void validateHasSourcePaths(const vector<string>& sourcePaths, const string& path) {
    if (!hasSourcePaths(sourcePaths)) {
        throw FileError(
            path,
            "ShaderFile::Impl::Impl",
            "has empty source paths sequence"
        );
    }
}

static const bool isValidTypeFormat(const Node& type) {
    try {
        type.as<string>();
        return type.IsScalar();
    }
    catch (const BadConversion& _) {
        return false;
    }
}

static void validateTypeFormat(const Node& type, const string& path) {
    if (!isValidTypeFormat(type)) {
        throw FileError(
            path,
            "ShaderFile::Impl::Impl",
            "has a type in an invalid format "
            "(must be a scalar value)"
        );
    }
}

static const bool isValidSourcePathsFormat(const Node& sourcePaths) {
    try {
        sourcePaths.as<vector<string>>();
        return sourcePaths.IsSequence();
    }
    catch (const BadConversion& _) {
        return false;
    }
}

static void validateSourcePathsFormat(const Node& sourcePaths, const string& path) {
    if (!isValidSourcePathsFormat(sourcePaths)) {
        throw FileError(
            path,
            "ShaderFile::Impl::Impl",
            "has source paths in an invalid format "
            "(must be a sequence of scalar values)"
        );
    }
}

static void validateData(const Node& file, const string& path) {
    for (Data data : file) {
        validateTypeFormat(data.first, path);
        validateSourcePathsFormat(data.second, path);
        validateIsValidType(getType(data), path);
        validateHasSourcePaths(getSourcePaths(data), path);
    }
}

static const bool hasType(const Node& file, const string& type) {
    return existsIn(file, [&](Data data) {
        return getType(data) == type;
    });
}

static const bool hasRequiredTypes(const Node& file) {
    static const vector<string> REQUIRED_TYPES { "vert", "frag" };

    return !existsIn(REQUIRED_TYPES, [&](const string& requiredType) {
        return !hasType(file, requiredType);
    });
}

static void validateHasRequiredTypes(const Node& file, const string& path) {
    if (!hasRequiredTypes(file)) {
        throw FileError(
            path,
            "ShaderFile::Impl::Impl",
            "must have atleast 1 vertex and 1 fragment source"
        );
    }
}

static const Node& getValidFile(const Node& file, const string& path) {
    validateData(file, path);
    validateHasRequiredTypes(file, path);
    return file;
}

Shader::Impl::Impl(const string& path, const ShaderSources& shaderSources)
    : Impl(getValidFile(LoadFile(path), path), shaderSources) {}

static ShaderProgramPtr getShaderProgram(const Node& file, const ShaderSources& shaderSources) {
    ShaderProgram::Objects objects;

    for (Data data : file) {
        ShaderObject::Sources sources;

        for (const auto& sourcePath : getSourcePaths(data)) {
            sources.push_back(shaderSources[sourcePath + "." + getType(data)]);
        }

        objects.push_back(new ShaderObject(sources));
    }

    ShaderProgramPtr shaderProgram(new ShaderProgram(objects));
    for (auto object : objects) delete object;
    return shaderProgram;
}

Shader::Impl::Impl(const Node& file, const ShaderSources& shaderSources)
    : shaderProgram(getShaderProgram(file, shaderSources)) {}

} // namespace onux
