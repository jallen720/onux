#include "utils/File.hpp"

#include <fstream>

#include "utils/split.hpp"
#include "exceptions/FileError.hpp"
#include "exceptions/validators/validateNotEmpty.hpp"

using std::string;
using std::ifstream;
using std::istreambuf_iterator;

namespace onux {

struct File::Impl {
    const string contents;

    explicit Impl(const string& path);
};

static const string& getValidPath(const string& path) {
    validateNotEmpty("path", "File::File", path);
    return path;
}

File::File(const string& path)
    : impl(new Impl(getValidPath(path))) {}

File::~File() {}

void File::forEachLine(LineCB lineCB) const {
    for (const string& line : split(impl->contents, '\n')) {
        lineCB(line);
    }
}

const string& File::getContents() const {
    return impl->contents;
}

// Implementation

static void validateStream(const ifstream& stream, const string& path) {
    if (!stream.is_open()) {
        throw FileError(
            path,
            "File::Impl",
            "failed to open"
        );
    }
}

static const string getValidContents(const string& path) {
    ifstream stream(path);
    validateStream(stream, path);

    string contents {
        istreambuf_iterator<char>(stream),
        istreambuf_iterator<char>()
    };

    stream.close();
    return contents;
}

File::Impl::Impl(const string& path)
    : contents(getValidContents(path)) {}

} // namespace onux
