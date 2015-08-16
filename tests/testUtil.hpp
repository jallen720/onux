#pragma once

#include <string>
#include <functional>
#include <GL/glew.h>

using std::string;
using std::function;

const string testShaderPath(const string&);
void expectNoThrow(const function<void()>&);
void expectGLError(const GLenum, const function<void()>&);

/*
class GLObject;
class GLData;

const string testTextureImagePath(const string&);
void assertGLError(const GLenum, const function<void()>&);
void expectNoGLError(const function<void()>&);
void assertNoGLError(const function<void()>&);
void existsTest(const GLData&);
void existsTest(const GLObject&);
void destroyTest(const GLData&);
void destroyTest(const GLObject&);
void destroyResetsTargetTest(const GLData&, const GLenum);
void bindTest(const GLData&, const GLenum);
void releaseTest(const GLData&, const GLenum);
void getIDTest(
  const GLint, const GLObject&,
  const GLint, const GLObject&
);
void getIDTest(const GLObject&, const GLObject&);
void magickErrorFinder(const function<void()>&);
*/
