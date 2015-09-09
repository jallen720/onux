#include "Scene.hpp"

#include <sstream>
#include <stdexcept>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using std::stringstream;
using std::runtime_error;

// bool Model::initMaterials(const aiScene* scene, const string& path) {
//   // Extract the directory part from the file name
//   string::size_type SlashIndex = path.find_last_of("/");
//   string Dir;

  // Dir = SlashIndex == string::npos ? "."
  //       : SlashIndex == 0 ? "/"
  //       : path.substr(0, SlashIndex);

//   bool Ret = true;

//   // Initialize the materials
//   for (auto i = 0u; i < scene->mNumMaterials ; i++) {
//     const aiMaterial* pMaterial = scene->mMaterials[i];

//     m_Textures[i] = NULL;

//     if (pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0) {
//       aiString Path;

//       if (pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &Path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS) {
//         string FullPath = Dir + "/" + Path.data;
//         m_Textures[i] = new Texture(GL_TEXTURE_2D, FullPath.c_str());

//         if (!m_Textures[i]->Load()) {
//           printf("Error loading texture '%s'\n", FullPath.c_str());
//           delete m_Textures[i];
//           m_Textures[i] = NULL;
//           Ret = false;
//         }
//         else {
//           printf("Loaded texture '%s'\n", FullPath.c_str());
//         }
//       }
//     }

//     // Load a white texture in case the model does not include its own texture
//     if (!m_Textures[i]) {
//       m_Textures[i] = new Texture(GL_TEXTURE_2D, "../Content/white.png");

//       Ret = m_Textures[i]->Load();
//     }
//   }

//   return Ret;
// }

void Scene::deleteMeshes() {
  for (const Mesh* mesh : meshes) {
    delete mesh;
  }
}

static const string assimpErrorMsg(const string& msg) {
  stringstream stream;
  stream << "ASSIMP ERROR: " << msg << "\n";
  return stream.str();
}

static void validateScene(
  const aiScene* scene,
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

static Scene::Meshes loadMeshes(const aiScene* scene) {
  vector<const Mesh*> meshes;

  for (auto i = 0u; i < scene->mNumMeshes; i++) {
    meshes.push_back(new Mesh(scene->mMeshes[i]));
  }

  return meshes;
}

Scene::Scene(const string& path)
  : scene(loadScene(path, importer))
  , meshes(loadMeshes(scene)) {}

Scene::~Scene() {
  deleteMeshes();
}

Scene::Meshes& Scene::getMeshes() const {
  return meshes;
}
