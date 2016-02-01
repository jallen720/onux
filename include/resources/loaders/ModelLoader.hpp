#pragma once

#include "resources/loaders/ResourceLoader.hpp"
#include "graphics/Model.hpp"

namespace onux {

class ModelLoader : public ResourceLoader<const Model> {
protected:
    // ResourceLoader
    virtual const std::string& getSubDirectory() const override;
    virtual Resource load(const std::string& path) const override;
};

} // namespace onux
