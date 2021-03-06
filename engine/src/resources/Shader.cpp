#include "resources/Shader.hpp"

#include <vector>
#include <map>
#include <yaml-cpp/yaml.h>

#include "resources/utils/ShaderObjectData.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"
#include "exceptions/FileError.hpp"
#include "utils/existsIn.hpp"

using std::string;
using std::vector;
using std::pair;
using YAML::Node;
using YAML::LoadFile;

namespace onux {

using ShaderObjectDatas = vector<ShaderObjectData>;

struct Shader::Impl {
    const ShaderObjectDatas shaderObjectDatas;

    explicit Impl(const string& path);
    Impl(const Node& file, const string& path);
};

auto Shader::create(const string& path) -> Ptr {
    validateNotEmpty("path", "Shader::create", path);
    return Ptr(new Shader(path));
}

Shader::Shader(const string& path)
    : impl(new Impl(path)) {}

Shader::~Shader() {}

void Shader::forEachShaderObjectData(ShaderObjectDataCB shaderObjectDataCB) const {
    for (const ShaderObjectData& shaderObjectData : impl->shaderObjectDatas) {
        shaderObjectDataCB(shaderObjectData);
    }
}

// Implementation

static void validateTypeFormat(const Node& type, const string& path) {
    if (!type.IsScalar()) {
        throw FileError(
            path,
            "Shader::Impl::Impl",
            "has a type in an invalid format (must be a scalar string)"
        );
    }
}

static void validateSourcePathsFormat(const Node& sourcePaths, const string& path) {
    if (!sourcePaths.IsSequence()) {
        throw FileError(
            path,
            "Shader::Impl::Impl",
            "has source paths in an invalid format "
            "(must be a sequence of strings)"
        );
    }
}

using Data = const pair<const Node&, const Node&>&;

static void validateDataFormats(const Node& file, const string& path) {
    for (Data data : file) {
        validateTypeFormat(data.first, path);
        validateSourcePathsFormat(data.second, path);
    }
}

static const Node& getValidFile(const Node& file, const string& path) {
    validateDataFormats(file, path);
    return file;
}

Shader::Impl::Impl(const string& path)
    : Impl(getValidFile(LoadFile(path), path), path) {}

static const string getType(Data data) {
    return data.first.as<string>();
}

static const ShaderObjectData::SourcePaths getSourcePaths(Data data) {
    return data.second.as<ShaderObjectData::SourcePaths>();
}

static ShaderObjectDatas loadShaderObjectDatas(const Node& file) {
    ShaderObjectDatas shaderObjectDatas;

    for (Data data : file) {
        shaderObjectDatas.emplace_back(
            getType(data),
            getSourcePaths(data)
        );
    }

    return shaderObjectDatas;
}

static const bool hasType(const ShaderObjectDatas& shaderObjectDatas, const string& type) {
    return existsIn(shaderObjectDatas, [&](const ShaderObjectData& shaderObjectData) {
        return shaderObjectData.getType() == type;
    });
}

static const bool hasRequiredTypes(const ShaderObjectDatas& shaderObjectDatas) {
    static const vector<string> REQUIRED_TYPES { "vert", "frag" };

    return !existsIn(REQUIRED_TYPES, [&](const string& requiredType) {
        return !hasType(shaderObjectDatas, requiredType);
    });
}

static void validateHasRequiredTypes(
    const ShaderObjectDatas& shaderObjectDatas,
    const string&            path
) {
    if (!hasRequiredTypes(shaderObjectDatas)) {
        throw FileError(
            path,
            "Shader::Impl::Impl",
            "must have atleast 1 vertex and 1 fragment source"
        );
    }
}

static ShaderObjectDatas getValidShaderObjectDatas(const Node& file, const string& path) {
    ShaderObjectDatas shaderObjectDatas = loadShaderObjectDatas(file);
    validateHasRequiredTypes(shaderObjectDatas, path);
    return shaderObjectDatas;
}

Shader::Impl::Impl(const Node& file, const string& path)
    : shaderObjectDatas(getValidShaderObjectDatas(file, path)) {}

} // namespace onux
