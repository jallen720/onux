const static GLsizei VERTEX_ARRAY_COUNT = 2;
const static uint    VERTEX_DATA_COUNT  = 24;
const static uint    ELEMENT_DATA_COUNT = 6;

static GLfloat vertexData[VERTEX_ARRAY_COUNT][VERTEX_DATA_COUNT] {
  {
    -0.7f,-0.9f, 0.0f,  0.0f, 0.5f, 0.5f, // Bottom left
    -0.9f, 0.9f, 0.0f,  0.0f, 0.5f, 0.5f, // Top left
    -0.1f, 0.3f, 0.0f,  0.0f, 0.5f, 0.5f, // Top right
    -0.1f,-0.9f, 0.0f,  0.0f, 0.5f, 0.5f, // Bottom right
  }, {
     0.1f,-0.8f, 0.0f,  0.5f, 0.0f, 0.5f, // Bottom left
     0.1f, 0.9f, 0.0f,  0.5f, 0.0f, 0.5f, // Top left
     0.4f, 0.9f, 0.0f,  0.5f, 0.0f, 0.5f, // Top right
     0.9f,-0.9f, 0.0f,  0.5f, 0.0f, 0.5f, // Bottom right
  },
};

static const GLuint elementData[VERTEX_ARRAY_COUNT][ELEMENT_DATA_COUNT] {
  {
    0, 1, 2,
    0, 2, 3,
  },
};
