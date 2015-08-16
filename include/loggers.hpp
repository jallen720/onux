#pragma once

class OpenGLData;

void logCreation(const OpenGLData* dataObject, const char* name);
void logCreation(const unsigned int id, const char* name);
void logDestruction(const OpenGLData* dataObject, const char* name);
void logDestruction(const unsigned int id, const char* name);
