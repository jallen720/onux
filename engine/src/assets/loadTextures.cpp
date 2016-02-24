#include "assets/loadTextures.hpp"

#include <string>

#include "gl/Texture.hpp"
#include "resources/Image.hpp"

using std::string;

namespace onux {

UniqueMap<Texture>::ElementMap loadTextures(const UniqueMap<Image>& images) {
    UniqueMap<Texture>::ElementMap textureMap;

    images.forEach([&](const Image* image, const string& path) {
        textureMap[path] = Texture::create(image);
    });

    return textureMap;
}

} // namespace onux
