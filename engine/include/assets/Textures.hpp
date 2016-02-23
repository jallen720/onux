#pragma once

#include "gl/Texture.hpp"
#include "utils/UniqueMap.hpp"
#include "resources/Resources.hpp"
#include "resources/Image.hpp"

namespace onux {

class Textures : public UniqueMap<Texture> {
public:
    Textures(const Resources<Image>& images);
};

} // namespace onux


