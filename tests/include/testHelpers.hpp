#pragma once

#include <functional>
#include <GL/glew.h>

void expectGlError(const GLenum error, const std::function<void()>& block);
void magickErrorFinder(const std::function<void()>&);
