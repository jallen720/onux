#include "resources/files/ShaderObjectData.hpp"

#include "exceptions/argErrors/InvalidArgProperty.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"
#include "utils/toString.hpp"
#include "utils/contains.hpp"

#include "MACROS/ONUX_MOVE_ONLY_IMPLS.hpp"

using std::vector;
using std::move;
using std::string;

namespace onux {

struct ShaderObjectData::Impl {
    const string      type;
    const SourcePaths sourcePaths;
};

static void validateType(const string& type) {
    static const vector<string> VALID_TYPES {
        "vert",
        "tesc",
        "tese",
        "geom",
        "frag",
        "comp",
    };

    if (!contains(VALID_TYPES, type)) {
        throw InvalidArg(
            "type",
            "ShaderObjectData::ShaderObjectData",
            VALID_TYPES
        );
    }
}

static const string& getValidType(const string& type) {
    validateType(type);
    return type;
}

static void validateSourcePaths(const ShaderObjectData::SourcePaths& sourcePaths) {
    static const size_t MIN_SOURCE_PATH_COUNT = 1;

    if (sourcePaths.size() < MIN_SOURCE_PATH_COUNT) {
        throw InvalidArgProperty(
            "sourcePaths",
            "ShaderObjectData::ShaderObjectData",
            "count",
            ">= " + toString(MIN_SOURCE_PATH_COUNT)
        );
    }
}

static const ShaderObjectData::SourcePaths& getValidSourcePaths(
    const ShaderObjectData::SourcePaths& sourcePaths
) {
    validateSourcePaths(sourcePaths);
    return sourcePaths;
}

ShaderObjectData::ShaderObjectData(const string& type, const SourcePaths& sourcePaths)
    : impl(new Impl {
        getValidType(type),
        getValidSourcePaths(sourcePaths),
    }) {}

ONUX_MOVE_ONLY_IMPLS(ShaderObjectData)

const string& ShaderObjectData::getType() const {
    return impl->type;
}

auto ShaderObjectData::getSourcePaths() const -> const SourcePaths& {
    return impl->sourcePaths;
}

} // namespace onux
