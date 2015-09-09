#include "helpers.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <Magick++.h>

using std::cerr;
using std::endl;
using std::ifstream;
using std::runtime_error;

static const char LINE_DELIMITER = '\r';

const string readFile(const string& path) {
  ifstream file;
  file.open(path);

  if (!file.is_open()) {
    throw runtime_error("Failed to open " + path);
  }

  string contents;
  string line;

  // Write all lines in file including newline characters (or else shader will
  // not compile) to contents string.
  while (getline(file, line, LINE_DELIMITER)) {
    contents += line;
  }

  file.close();
  return contents;
}

const string fileExtension(const string& path) {
  const size_t dotPosition = path.find_last_of(".");
  return dotPosition == string::npos ? "" : path.substr(dotPosition + 1);
}

void magickErrorFinder(const function<void()>& block) {
  using namespace Magick;

  try {
    block();
    cerr << "No Magick++ error thrown" << endl;
  } catch (const ErrorUndefined& e) {
    cerr << "ErrorUndefined thrown: " << e.what() << endl;
  } catch (const ErrorBlob& e) {
    cerr << "ErrorBlob thrown: " << e.what() << endl;
  } catch (const ErrorCache& e) {
    cerr << "ErrorCache thrown: " << e.what() << endl;
  } catch (const ErrorCoder& e) {
    cerr << "ErrorCoder thrown: " << e.what() << endl;
  } catch (const ErrorConfigure& e) {
    cerr << "ErrorConfigure thrown: " << e.what() << endl;
  } catch (const ErrorCorruptImage& e) {
    cerr << "ErrorCorruptImage thrown: " << e.what() << endl;
  } catch (const ErrorDelegate& e) {
    cerr << "ErrorDelegate thrown: " << e.what() << endl;
  } catch (const ErrorDraw& e) {
    cerr << "ErrorDraw thrown: " << e.what() << endl;
  } catch (const ErrorFileOpen& e) {
    cerr << "ErrorFileOpen thrown: " << e.what() << endl;
  } catch (const ErrorImage& e) {
    cerr << "ErrorImage thrown: " << e.what() << endl;
  } catch (const ErrorMissingDelegate& e) {
    cerr << "ErrorMissingDelegate thrown: " << e.what() << endl;
  } catch (const ErrorModule& e) {
    cerr << "ErrorModule thrown: " << e.what() << endl;
  } catch (const ErrorMonitor& e) {
    cerr << "ErrorMonitor thrown: " << e.what() << endl;
  } catch (const ErrorOption& e) {
    cerr << "ErrorOption thrown: " << e.what() << endl;
  } catch (const ErrorRegistry& e) {
    cerr << "ErrorRegistry thrown: " << e.what() << endl;
  } catch (const ErrorResourceLimit& e) {
    cerr << "ErrorResourceLimit thrown: " << e.what() << endl;
  } catch (const ErrorStream& e) {
    cerr << "ErrorStream thrown: " << e.what() << endl;
  } catch (const ErrorType& e) {
    cerr << "ErrorType thrown: " << e.what() << endl;
  } catch (const ErrorXServer& e) {
    cerr << "ErrorXServer thrown: " << e.what() << endl;
  } catch(...) {
    cerr << "Unknown error thrown" << endl;
  }
}
