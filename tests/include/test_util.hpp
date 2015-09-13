#pragma once

#include <string>
#include <functional>
#include <GL/glew.h>

const std::string testShaderPath(const std::string& name);
const std::string testImagePath(const std::string& name);
const std::string testModelPath(const std::string& name);
void expectNoThrow(const std::function<void()>& block);
void expectGLError(const GLenum error, const std::function<void()>& block);
void magickErrorFinder(const std::function<void()>&);

/*
void assertGLError(const GLenum, const std::function<void()>&);
void bindTest(const GLData&, const GLenum);
*/
