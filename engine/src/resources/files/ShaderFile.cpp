#include "resources/files/ShaderFile.hpp"

#include <vector>
#include <map>
#include <yaml-cpp/yaml.h>

#include "resources/files/ShaderObjectData.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"
#include "exceptions/FileError.hpp"
#include "utils/existsIn.hpp"

using std::string;
using std::vector;
using std::pair;
using YAML::Node;
using YAML::LoadFile;

namespace onux {

using ShaderObjectDatas = vector<ShaderObjectData::Ptr>;

struct ShaderFile::Impl {
    const ShaderObjectDatas shaderObjectDatas;

    explicit Impl(const string& path);
    Impl(const Node& file, const string& path);
};

static const string& getValidPath(const string& path) {
    validateNotEmpty("path", "ShaderFile::ShaderFile", path);
    return path;
}

ShaderFile::ShaderFile(const string& path)
    : impl(new Impl(getValidPath(path))) {}

ShaderFile::~ShaderFile() {}

void ShaderFile::forEachShaderObjectData(ShaderObjectDataCB shaderObjectDataCB) const {
    for (const ShaderObjectData::Ptr& shaderObjectData : impl->shaderObjectDatas) {
        shaderObjectDataCB(*shaderObjectData);
    }
}

// Implementation

static void validateTypeFormat(const Node& type, const string& path) {
    if (!type.IsScalar()) {
        throw FileError(
            path,
            "ShaderFile::Impl::Impl",
            "has a type in an invalid format (must be a scalar string)"
        );
    }
}

static void validateSourcePathsFormat(const Node& sourcePaths, const string& path) {
    if (!sourcePaths.IsSequence()) {
        throw FileError(
            path,
            "ShaderFile::Impl::Impl",
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

ShaderFile::Impl::Impl(const string& path)
    : Impl(getValidFile(LoadFile(path), path), path) {}

static const string getType(Data data) {
    return data.first.as<string>();
}

static const IShaderObjectData::SourcePaths getSourcePaths(Data data) {
    return data.second.as<IShaderObjectData::SourcePaths>();
}

static ShaderObjectDatas getShaderObjectDatas(const Node& file) {
    ShaderObjectDatas shaderObjectDatas;

    for (Data data : file) {
        shaderObjectDatas.emplace_back(new ShaderObjectData(
            getType(data),
            getSourcePaths(data)
        ));
    }

    return shaderObjectDatas;
}

static const bool hasType(const ShaderObjectDatas& shaderObjectDatas, const string& type) {
    return existsIn(shaderObjectDatas, [&](const ShaderObjectData::Ptr& shaderObjectData) {
        return shaderObjectData->getType() == type;
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
    const string& path
) {
    if (!hasRequiredTypes(shaderObjectDatas)) {
        throw FileError(
            path,
            "ShaderFile::Impl::Impl",
            "must have atleast 1 vertex and 1 fragment source"
        );
    }
}

static ShaderObjectDatas getValidShaderObjectDatas(const Node& file, const string& path) {
    ShaderObjectDatas shaderObjectDatas = getShaderObjectDatas(file);
    validateHasRequiredTypes(shaderObjectDatas, path);
    return shaderObjectDatas;
}

ShaderFile::Impl::Impl(const Node& file, const string& path)
    : shaderObjectDatas(getValidShaderObjectDatas(file, path)) {}

} // namespace onux
