#pragma once

#include "utils/UniqueMap.hpp"

namespace onux {

class Texture;
class Image;

UniqueMap<Texture> loadTextures(const UniqueMap<Image>& images);

} // namespace onux
