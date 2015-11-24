#include "testHelpers.hpp"

#include <iostream>
#include <gtest/gtest.h>
#include <Magick++.h>

using std::cerr;
using std::function;

void expectGlError(const GLenum error, const function<void()>& block) {
  // Assert no error has already been generated before testing block error
  // generation.
  ASSERT_EQ(GL_NO_ERROR, glGetError());

  // Run block where error is expected to be generated.
  block();

  // Expect error was generated during block.
  EXPECT_EQ(error, glGetError());
}

void magickErrorFinder(const function<void()>& block) {
  using namespace Magick;

  try {
    block();
    cerr << "No Magick++ error thrown\n";
  } catch (const ErrorUndefined& e) {
    cerr << "ErrorUndefined thrown: " << e.what() << "\n";
  } catch (const ErrorBlob& e) {
    cerr << "ErrorBlob thrown: " << e.what() << "\n";
  } catch (const ErrorCache& e) {
    cerr << "ErrorCache thrown: " << e.what() << "\n";
  } catch (const ErrorCoder& e) {
    cerr << "ErrorCoder thrown: " << e.what() << "\n";
  } catch (const ErrorConfigure& e) {
    cerr << "ErrorConfigure thrown: " << e.what() << "\n";
  } catch (const ErrorCorruptImage& e) {
    cerr << "ErrorCorruptImage thrown: " << e.what() << "\n";
  } catch (const ErrorDelegate& e) {
    cerr << "ErrorDelegate thrown: " << e.what() << "\n";
  } catch (const ErrorDraw& e) {
    cerr << "ErrorDraw thrown: " << e.what() << "\n";
  } catch (const ErrorFileOpen& e) {
    cerr << "ErrorFileOpen thrown: " << e.what() << "\n";
  } catch (const ErrorImage& e) {
    cerr << "ErrorImage thrown: " << e.what() << "\n";
  } catch (const ErrorMissingDelegate& e) {
    cerr << "ErrorMissingDelegate thrown: " << e.what() << "\n";
  } catch (const ErrorModule& e) {
    cerr << "ErrorModule thrown: " << e.what() << "\n";
  } catch (const ErrorMonitor& e) {
    cerr << "ErrorMonitor thrown: " << e.what() << "\n";
  } catch (const ErrorOption& e) {
    cerr << "ErrorOption thrown: " << e.what() << "\n";
  } catch (const ErrorRegistry& e) {
    cerr << "ErrorRegistry thrown: " << e.what() << "\n";
  } catch (const ErrorResourceLimit& e) {
    cerr << "ErrorResourceLimit thrown: " << e.what() << "\n";
  } catch (const ErrorStream& e) {
    cerr << "ErrorStream thrown: " << e.what() << "\n";
  } catch (const ErrorType& e) {
    cerr << "ErrorType thrown: " << e.what() << "\n";
  } catch (const ErrorXServer& e) {
    cerr << "ErrorXServer thrown: " << e.what() << "\n";
  } catch(...) {
    cerr << "Unknown error thrown\n";
  }
}
