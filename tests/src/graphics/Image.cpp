#include "graphics/Image.hpp"

#include <stdexcept>
#include <Magick++.h>

#include "fixtures/ImageTest.hpp"
#include "testUtil.hpp"

using std::runtime_error;
using Magick::ErrorMissingDelegate;
using Magick::ErrorBlob;
using onux::Image;

TEST_F(ImageTest, validCreation) {
  expectNoThrow([] {
    const Image image(testImagePath("valid.png"));
  });
}

TEST_F(ImageTest, emptyPath) {
  EXPECT_THROW(
    const Image image(""),
    runtime_error
  );
}

TEST_F(ImageTest, invalidFileExtension) {
  EXPECT_THROW(
    const Image image(testImagePath("invalid_format.pngg")),
    ErrorMissingDelegate
  );
}

TEST_F(ImageTest, fileDoesNotExist) {
  EXPECT_THROW(
    const Image image("does_not_exist.png"),
    ErrorBlob
  );
}
