#include "resources/Image.hpp"

#include <Magick++.h>

#include "tests/fixtures/resources/ImageTest.hpp"
#include "tests/utils/expectNoThrow.hpp"
#include "tests/utils/validResourcePath.hpp"
#include "tests/utils/invalidResourcePath.hpp"
#include "exceptions/argErrors/EmptyStringArg.hpp"

using Magick::ErrorMissingDelegate;
using Magick::ErrorBlob;
using onux::Image;
using onux::EmptyStringArg;

TEST_F(ImageTest, validCreation) {
    expectNoThrow([] {
        Image::create(validResourcePath("images", "valid.png"));
    });
}

TEST_F(ImageTest, emptyPath) {
    EXPECT_THROW(Image::create(""), EmptyStringArg);
}

TEST_F(ImageTest, invalidFileExtension) {
    EXPECT_THROW(
        Image::create(invalidResourcePath("images", "invalid_format.pngg")),
        ErrorMissingDelegate
    );
}

TEST_F(ImageTest, fileDoesNotExist) {
    EXPECT_THROW(Image::create("does_not_exist.png"), ErrorBlob);
}
