#include "engine/Entity.hpp"

#include <GL/glew.h>

#include "assets/Model.hpp"
#include "graphics/Camera.hpp"
#include "graphics/Transform.hpp"

#include "MACROS/ONUX_PIMPL_COPY_IMPLS.hpp"

namespace onux {

struct Entity::Impl {
    const Model* model;
    Transform    transform;
};

Entity::Entity(const Model* model)
    : impl(new Impl { model }) {}

ONUX_PIMPL_COPY_IMPLS(Entity)

const Model* Entity::getModel() const {
    return impl->model;
}

Transform& Entity::getTransform() {
    return impl->transform;
}

const Transform& Entity::getTransform() const {
    return impl->transform;
}

} // namespace onux
