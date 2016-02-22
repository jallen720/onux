#include "gl/Texture.hpp"

#include <map>
#include <string>
#include <vector>

#include "utils/toString.hpp"
#include "gl/interfaces/IImage.hpp"
#include "utils/ValidGLValues.hpp"
#include "gl/utils/getInt.hpp"
#include "exceptions/Error.hpp"
#include "exceptions/argErrors/InvalidMapKey.hpp"
#include "exceptions/argErrors/InvalidMapValue.hpp"
#include "exceptions/argErrors/InvalidArg.hpp"
#include "exceptions/validators/validateNotNull.hpp"

#include "MACROS/ONUX_VALID_GL_VALUE.hpp"

using std::map;
using std::string;
using std::vector;

namespace onux {

struct Texture::Impl {
    void loadImage(const IImage* image) const;
    void loadOptions(Options& options) const;
};

// Texture represents 1 texture.
static const GLsizei TEXTURE_COUNT = 1;

static GLuint createTexture() {
    GLuint id;
    glGenTextures(TEXTURE_COUNT, &id);
    return id;
}

static const ValidGLValues VALID_WRAP_VALUES({
    ONUX_VALID_GL_VALUE(GL_CLAMP_TO_EDGE),
    ONUX_VALID_GL_VALUE(GL_MIRRORED_REPEAT),
    ONUX_VALID_GL_VALUE(GL_REPEAT),
});

static const ValidGLValues VALID_MIN_FILTER_VALUES({
    ONUX_VALID_GL_VALUE(GL_NEAREST),
    ONUX_VALID_GL_VALUE(GL_LINEAR),
    ONUX_VALID_GL_VALUE(GL_NEAREST_MIPMAP_NEAREST),
    ONUX_VALID_GL_VALUE(GL_LINEAR_MIPMAP_NEAREST),
    ONUX_VALID_GL_VALUE(GL_NEAREST_MIPMAP_LINEAR),
    ONUX_VALID_GL_VALUE(GL_LINEAR_MIPMAP_LINEAR),
});

static const ValidGLValues VALID_MAG_FILTER_VALUES({
    ONUX_VALID_GL_VALUE(GL_NEAREST),
    ONUX_VALID_GL_VALUE(GL_LINEAR),
});

static const ValidGLValues VALID_OPTION_KEYS({
    ONUX_VALID_GL_VALUE(GL_TEXTURE_WRAP_S),
    ONUX_VALID_GL_VALUE(GL_TEXTURE_WRAP_T),
    ONUX_VALID_GL_VALUE(GL_TEXTURE_MIN_FILTER),
    ONUX_VALID_GL_VALUE(GL_TEXTURE_MAG_FILTER),
});

static const map<const GLenum, const ValidGLValues&> VALID_OPTION_VALUES {
    { GL_TEXTURE_WRAP_S    , VALID_WRAP_VALUES       },
    { GL_TEXTURE_WRAP_T    , VALID_WRAP_VALUES       },
    { GL_TEXTURE_MIN_FILTER, VALID_MIN_FILTER_VALUES },
    { GL_TEXTURE_MAG_FILTER, VALID_MAG_FILTER_VALUES },
};

static void validateOptionKey(const GLenum optionKey) {
    if (!VALID_OPTION_KEYS.contains(optionKey)) {
        throw InvalidMapKey(
            "options",
            "Texture::create",
            VALID_OPTION_KEYS.getNames()
        );
    }
}

static void validateOptionValue(const GLenum optionKey, const GLint optionValue) {
    if (!VALID_OPTION_VALUES.at(optionKey).contains(optionValue)) {
        throw InvalidMapValue(
            "options",
            "Texture::create",
            VALID_OPTION_KEYS.getName(optionKey),
            VALID_OPTION_VALUES.at(optionKey).getNames()
        );
    }
}

static void validateOptions(Texture::Options& options) {
    for (const Texture::Options::value_type& option : options) {
        validateOptionKey(option.first);
        validateOptionValue(option.first, option.second);
    }
}

auto Texture::create(const IImage* image, Options& options) -> Ptr {
    validateNotNull("image", "Texture::create", image);
    validateOptions(options);
    return Ptr(new Texture(image, options, createTexture()));
}

Texture::Texture(const IImage* image, Options& options, const GLuint id)
    : GLData(id)
    , impl(new Impl()) {
    bind(0);
    impl->loadImage(image);
    impl->loadOptions(options);
}

Texture::~Texture() {
    glDeleteTextures(TEXTURE_COUNT, &getID());
}

static void validateUnit(const GLuint unit) {
    static const GLuint MAX_UNIT = getInt(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS) - 1;

    if (unit > MAX_UNIT) {
        throw InvalidArg("unit", "Texture::bind", "<= " + toString(MAX_UNIT));
    }
}

static const GLenum TARGET = GL_TEXTURE_2D;

void Texture::bind(const GLuint unit) const {
    validateUnit(unit);
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(TARGET, getID());
}

Texture::Options Texture::DEFAULT_OPTIONS {
    { GL_TEXTURE_MIN_FILTER, GL_LINEAR },
    { GL_TEXTURE_MAG_FILTER, GL_LINEAR },
};

// Implementation

void Texture::Impl::loadImage(const IImage* image) const {
    static const GLint  LEVEL_OF_DETAIL = 0; // 0 is base image LOD
    static const GLint  INTERNAL_FORMAT = GL_RGBA;
    static const GLint  BORDER_WIDTH    = 0; // Must be 0 apparently?
    static const GLenum TEXEL_DATA_TYPE = GL_UNSIGNED_BYTE;

    // Load texture data from image
    glTexImage2D(
        TARGET,             // Target
        LEVEL_OF_DETAIL,    // Level of detail
        INTERNAL_FORMAT,    // Internal format
        image->getWidth(),  // Image width
        image->getHeight(), // Image height
        BORDER_WIDTH,       // Border width
        INTERNAL_FORMAT,    // Texel data format (must match internal format)
        TEXEL_DATA_TYPE,    // Texel data type
        image->getData()    // Pointer to image data
    );
}

void Texture::Impl::loadOptions(Options& options) const {
    for (const Options::value_type& option : options) {
        glTexParameteri(
            TARGET,
            option.first,
            option.second
        );
    }
}

} // namespace onux
