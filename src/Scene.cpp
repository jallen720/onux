#include "Scene.hpp"

#include <sstream>
#include <stdexcept>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using std::string;
using std::stringstream;
using std::runtime_error;
using Assimp::Importer;

static const string assimpErrorMsg(const string& msg) {
  stringstream stream;
  stream << "ASSIMP ERROR: " << msg << "\n";
  return stream.str();
}

static void validateScene(
  const aiScene*  scene,
  const Importer& importer
) {
  if (!scene) {
    throw runtime_error(assimpErrorMsg(importer.GetErrorString()));
  }
}

static const aiScene* loadScene(const string& path, Importer& importer) {
  static const unsigned int IMPORT_FLAGS =
    aiProcess_GenSmoothNormals      |
    aiProcess_CalcTangentSpace      |
    aiProcess_Triangulate           |
    aiProcess_JoinIdenticalVertices |
    aiProcess_SortByPType;

  const aiScene* scene = importer.ReadFile(path, IMPORT_FLAGS);
  validateScene(scene, importer);
  return scene;
}

static const Scene::Meshes loadMeshes(const aiScene* scene) {
  Scene::Meshes meshes;

  for (auto i = 0u; i < scene->mNumMeshes; i++) {
    meshes.push_back({ scene->mMeshes[i] });
  }

  return meshes;
}

Scene::Scene(const string& path)
  : m_scene(loadScene(path, m_importer))
  , m_meshes(loadMeshes(m_scene)) {}

const Scene::Meshes& Scene::getMeshes() const {
  return m_meshes;
}
