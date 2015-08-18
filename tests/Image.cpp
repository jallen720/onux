#include "Image.hpp"

#include <stdexcept>
#include <Magick++.h>

#include "fixtures/ImageTest.hpp"
#include "testUtil.hpp"

using std::runtime_error;
using Magick::ErrorMissingDelegate;
using Magick::ErrorFileOpen;

TEST_F(ImageTest, validCreation) {
  expectNoThrow([] {
    Image(testImagePath("valid.png"));
  });
}

TEST_F(ImageTest, emptyPath) {
  EXPECT_THROW(Image(""), runtime_error);
}

TEST_F(ImageTest, invalidFileExtension) {
  EXPECT_THROW(
    Image(testImagePath("invalid_format.pngg")),
    ErrorMissingDelegate
  );
}

TEST_F(ImageTest, fileDoesNotExist) {
  EXPECT_THROW(
    Image("does_not_exist.png"),
    ErrorFileOpen
  );
}
