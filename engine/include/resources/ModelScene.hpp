#pragma once

#include <memory>
#include <string>
#include <vector>

namespace onux {

class MeshData;

class ModelScene {
public:
    using Ptr         = std::unique_ptr<const ModelScene>;
    using ImportFlags = const unsigned int;
    using MeshDatas   = std::vector<MeshData>;

public:
    static ImportFlags DEFAULT_IMPORT_FLAGS;

    static Ptr create(
        const std::string& path,
        ImportFlags        importFlags = DEFAULT_IMPORT_FLAGS
    );

public:
    ~ModelScene();
    const MeshDatas& getMeshDatas() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    ModelScene(
        const std::string& path,
        ImportFlags        importFlags
    );
};

} // namespace onux
