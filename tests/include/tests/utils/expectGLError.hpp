#pragma once

#include <functional>
#include <GL/glew.h>

void expectGLError(const GLenum error, const std::function<void()>& block);
