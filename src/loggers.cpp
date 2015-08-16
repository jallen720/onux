#include "loggers.hpp"

#include <iostream>

#include "OpenGLData.hpp"

using std::cout;
using std::endl;

static void logStatus(
  const unsigned int id,
  const char* name,
  const char* status
) {
  //cout << name << " [" << id << "] " << status << endl;
}

void logCreation(const OpenGLData* dataObject, const char* name) {
  logStatus(dataObject->getID(), name, "created");
}

void logCreation(const unsigned int id, const char* name) {
  logStatus(id, name, "created");
}

void logDestruction(const OpenGLData* dataObject, const char* name) {
  logStatus(dataObject->getID(), name, "destroyed");
}

void logDestruction(const unsigned int id, const char* name) {
  logStatus(id, name, "destroyed");
}
