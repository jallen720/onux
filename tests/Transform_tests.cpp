#include "Transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "fixtures/TransformTest.hpp"

using glm::translate;
using glm::rotate;
using glm::scale;
using glm::radians;

TEST_F(TransformTest, translate) {
  transform.translate(vec3(1, 0, 0));
  ASSERT_EQ(vec3(1, 0, 0), transform.getPosition());

  transform.translate(vec3(0, 1, 0));
  ASSERT_EQ(vec3(1, 1, 0), transform.getPosition());

  transform.translate(vec3(-1, 0, 1));
  ASSERT_EQ(vec3(0, 1, 1), transform.getPosition());
}

TEST_F(TransformTest, rotate) {
  transform.rotate(vec3(90, 0, 0));
  ASSERT_EQ(vec3(90, 0, 0), transform.getRotation());

  transform.rotate(vec3(0, 30, 0));
  ASSERT_EQ(vec3(90, 30, 0), transform.getRotation());

  transform.rotate(vec3(-30, 0, 90));
  ASSERT_EQ(vec3(60, 30, 90), transform.getRotation());
}

TEST_F(TransformTest, scale) {
  transform.scale(vec3(2, 1, 1));
  ASSERT_EQ(vec3(2, 1, 1), transform.getScale());

  transform.scale(vec3(1, 30, 1));
  ASSERT_EQ(vec3(2, 30, 1), transform.getScale());

  transform.scale(vec3(4, 0.5, 0.5));
  ASSERT_EQ(vec3(8, 15, 0.5), transform.getScale());
}

TEST_F(TransformTest, getMatrix) {
  transform.setScale(vec3(1, 2, 3));
  transform.setRotation(vec3(90, 80, 70));
  transform.setPosition(vec3(4, 5, 6));

  const auto correctMatrix =
    translate(rotate(rotate(rotate(scale(mat4()
    , vec3(1, 2, 3))
    , radians(90.f), vec3(1, 0, 0))
    , radians(80.f), vec3(0, 1, 0))
    , radians(70.f), vec3(0, 0, 1))
    , vec3(4, 5, 6));

  const auto incorrectMatrix =
    translate(rotate(rotate(rotate(scale(mat4()
    , vec3(1, 2, 3))
    , radians(90.f), vec3(1, 0, 0))
    , radians(81.f), vec3(0, 1, 0))
    , radians(70.f), vec3(0, 0, 1))
    , vec3(4, 5, 6));

  ASSERT_EQ(correctMatrix, transform.getMatrix());
  ASSERT_NE(incorrectMatrix, transform.getMatrix());
}
