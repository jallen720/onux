#include "graphics/ShaderSource.hpp"

#include "utils/File.hpp"
#include "utils/getExtension.hpp"
#include "exceptions/argErrors/InvalidArgProperty.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"
#include "utils/keys.hpp"

using std::string;

namespace onux {

struct ShaderSource::Impl {
    const GLenum type;
    const string code;

    explicit Impl(const string& path);
};

ShaderSource::Types ShaderSource::TYPES {
    { "vert", GL_VERTEX_SHADER          },
    { "tesc", GL_TESS_CONTROL_SHADER    },
    { "tese", GL_TESS_EVALUATION_SHADER },
    { "geom", GL_GEOMETRY_SHADER        },
    { "frag", GL_FRAGMENT_SHADER        },
    { "comp", GL_COMPUTE_SHADER         },
};

static const string& getValidPath(const string& path) {
    validateNotEmpty("path", "ShaderSource::ShaderSource", path);
    return path;
}

ShaderSource::ShaderSource(const string& path)
    : impl(new Impl(getValidPath(path))) {}

const GLenum ShaderSource::getType() const {
    return impl->type;
}

const GLchar* ShaderSource::getCode() const {
    return impl->code.c_str();
}

// Implementation

static const bool isValidExtension(const string& extension) {
    return ShaderSource::TYPES.count(extension) == 1;
}

static void validateExtension(const string& extension) {
    if (!isValidExtension(extension)) {
        throw InvalidArgProperty(
            "path",
            "ShaderSource::ShaderSource",
            "extension",
            keys(ShaderSource::TYPES)
        );
    }
}

static const GLenum getValidType(const string& path) {
    const string extension = getExtension(path);
    validateExtension(extension);
    return ShaderSource::TYPES.at(extension);
}

ShaderSource::Impl::Impl(const string& path)
    : type(getValidType(path))
    , code(File(path).getContents()) {}

} // namespace onux