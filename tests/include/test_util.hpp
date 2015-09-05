#pragma once

#include <string>
#include <functional>
#include <GL/glew.h>

using std::string;
using std::function;

const string testShaderPath(const string& name);
const string testImagePath(const string& name);
const string testModelPath(const string& name);
void expectNoThrow(const function<void()>& block);
void expectGLError(const GLenum error, const function<void()>& block);

/*
class GLObject;
class GLData;

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
*/
