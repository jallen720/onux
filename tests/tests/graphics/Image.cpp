#include "graphics/Image.hpp"

#include <Magick++.h>

#include "fixtures/ImageTest.hpp"
#include "utils/expectNoThrow.hpp"
#include "utils/testImagePath.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using Magick::ErrorMissingDelegate;
using Magick::ErrorBlob;
using onux::Image;
using onux::EmptyStringArg;

TEST_F(ImageTest, validCreation) {
  expectNoThrow([] {
    const Image image(testImagePath("valid.png"));
  });
}

TEST_F(ImageTest, emptyPath) {
  EXPECT_THROW(
    const Image image(""),
    EmptyStringArg
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
