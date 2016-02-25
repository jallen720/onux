#include "assets/loadTextures.hpp"

#include <string>

#include "gl/Texture.hpp"
#include "resources/Image.hpp"

using std::string;

namespace onux {

UniqueMap<Texture> loadTextures(const UniqueMap<Image>& images) {
    UniqueMap<Texture> textures;

    images.forEach([&](const Image* image, const string& path) {
        textures.add(path, Texture::create(image));
    });

    return textures;
}

} // namespace onux
