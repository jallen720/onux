#pragma once

#include <memory>
#include <string>
#include <functional>

namespace onux {

class File {
private:
    using LineCallback = const std::function<void(const std::string&)>&;

public:
    explicit File(const std::string& path);
    ~File();
    void forEachLine(LineCallback callback) const;
    const std::string& getContents() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
