#pragma once

#include <string>
#include <Magick++.h>

using std::string;
using Magick::Blob;

class Image {
  Blob blob;

  void loadBlob(const string& path);

public:
  Image(const string& path);
};
