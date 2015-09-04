#include "ViewTransform.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "fixtures/ViewTransformTest.hpp"

using glm::translate;
using glm::rotate;
using glm::scale;
using glm::radians;

TEST_F(ViewTransformTest, getMatrix) {
  viewTransform.scale(vec3(1, 2, 3));
  viewTransform.rotate(vec3(90, 80, 70));
  viewTransform.translate(vec3(4, 5, 6));

  // Rotation & position in a ViewTransform matrix are inverted.
  const auto correctMatrix =
    translate(rotate(rotate(rotate(scale(mat4()
    , vec3(1, 2, 3))
    , -radians(90.f), vec3(1, 0, 0))
    , -radians(80.f), vec3(0, 1, 0))
    , -radians(70.f), vec3(0, 0, 1))
    , -vec3(4, 5, 6));

  const auto incorrectMatrix =
    translate(rotate(rotate(rotate(scale(mat4()
    , vec3(1, 2, 3))
    , radians(90.f), vec3(1, 0, 0))
    , radians(80.f), vec3(0, 1, 0))
    , radians(70.f), vec3(0, 0, 1))
    , vec3(4, 5, 6));

  ASSERT_EQ(correctMatrix, viewTransform.getMatrix());
  ASSERT_NE(incorrectMatrix, viewTransform.getMatrix());
}
