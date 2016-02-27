#pragma once

#include <memory>
#include <string>
#include <functional>

struct aiMesh;

namespace onux {

class ModelScene {
public:
    using Ptr         = std::unique_ptr<const ModelScene>;
    using ImportFlags = const unsigned int;
    using MeshCB      = const std::function<void(const aiMesh*)>&;

public:
    static ImportFlags DEFAULT_IMPORT_FLAGS;

    static Ptr create(
        const std::string& path,
        ImportFlags        importFlags = DEFAULT_IMPORT_FLAGS
    );

public:
    ~ModelScene();
    const aiMesh* getMesh(const unsigned int index) const;
    void forEachMesh(MeshCB meshCB) const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    explicit ModelScene(
        const std::string& path,
        ImportFlags        importFlags
    );
};

} // namespace onux
