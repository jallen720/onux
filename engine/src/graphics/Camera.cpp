#include "graphics/Camera.hpp"

#include "graphics/Transform.hpp"

using glm::mat4;

namespace onux {

struct Camera::Impl {
    Transform transform;
    mat4      projection;

    explicit Impl(const mat4& projection);
};

Camera::Camera(const mat4& projection)
    : impl(new Impl(projection)) {}

Camera::~Camera() {}

Transform& Camera::getTransform() {
    return impl->transform;
}

const mat4& Camera::getProjection() const {
    return impl->projection;
}

// Implementation

Camera::Impl::Impl(const mat4& projection)
    : projection(projection) {}

} // namespace onux
