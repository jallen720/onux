#pragma once

#include <functional>
#include <GL/glew.h>

void expectNoThrow(const std::function<void()>& block);
void expectGlError(const GLenum error, const std::function<void()>& block);
void magickErrorFinder(const std::function<void()>&);
