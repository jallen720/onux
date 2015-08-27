#include "Scene.hpp"

#include <sstream>
#include <stdexcept>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using std::stringstream;
using std::runtime_error;

static const string assimpErrorMsg(const string& msg) {
  stringstream stream;
  stream << "ASSIMP ERROR: " << msg << "\n";
  return stream.str();
}

static void validateScene(
  const aiScene* scene,
  const Importer& importer
) {
  if (!scene)
    throw runtime_error(assimpErrorMsg(importer.GetErrorString()));
}

static const aiScene* loadScene(const string& path, Importer& importer) {
  static const unsigned int IMPORT_FLAGS =
    aiProcess_GenSmoothNormals      |
    aiProcess_CalcTangentSpace      |
    aiProcess_Triangulate           |
    aiProcess_JoinIdenticalVertices |
    aiProcess_SortByPType;

  auto scene = importer.ReadFile(path, IMPORT_FLAGS);
  validateScene(scene, importer);
  return scene;
}

static const vector<Mesh> loadMeshes(const aiScene* scene) {
  vector<Mesh> meshes;

  for (auto i = 0u; i < scene->mNumMeshes; i++)
    meshes.push_back({ scene->mMeshes[i] });

  return meshes;
}

Scene::Scene(const string& path)
  : scene(loadScene(path, importer))
  , meshes(loadMeshes(scene)) {

}

const vector<Mesh>& Scene::getMeshes() const {
  return meshes;
}
