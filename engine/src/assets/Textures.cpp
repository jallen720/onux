#include "assets/Textures.hpp"

#include <string>

using std::string;

namespace onux {

static void loadTextures(
    typename UniqueMap<Texture>::ElementMap& textureMap,
    const Resources<Image>&                  images
) {
    images.forEach([&](const Image* image, const string& path) {
        textureMap[path] = Texture::create(image);
    });
}

Textures::Textures(const Resources<Image>& images) {
    loadTextures(getElementMap(), images);
}

} // namespace onux
