#pragma once

#include <memory>
#include <string>
#include <functional>

namespace onux {

template<typename T>
class ResourceLoader {
public:
    typedef std::unique_ptr<T> Resource;

private:
    typedef const std::function<void(const std::string&, Resource)>& LoadCallback;

public:
    virtual ~ResourceLoader() {}
    const std::string getPath(const std::string& relativePath) const;
    void loadAll(LoadCallback loadCallback) const;

protected:
    virtual const std::string& getSubDirectory() const = 0;
    virtual Resource load(const std::string& path) const = 0;

private:
    const std::string getDirectory() const;
};

} // namespace onux

#include "resources/loaders/ResourceLoader.ipp"


