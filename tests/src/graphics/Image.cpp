#include "graphics/Image.hpp"

#include <Magick++.h>

#include "tests/fixtures/graphics/ImageTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "tests/utils/testImagePath.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using Magick::ErrorMissingDelegate;
using Magick::ErrorBlob;
using onux::Image;
using onux::EmptyStringArg;

TEST_F(ImageTest, validCreation) {
    expectNoThrow([] {
        Image(testImagePath("valid.png"));
    });
}

TEST_F(ImageTest, emptyPath) {
    EXPECT_THROW(Image(""), EmptyStringArg);
}

TEST_F(ImageTest, invalidFileExtension) {
    EXPECT_THROW(Image(testImagePath("invalid_format.pngg")), ErrorMissingDelegate);
}

TEST_F(ImageTest, fileDoesNotExist) {
    EXPECT_THROW(Image("does_not_exist.png"), ErrorBlob);
}
