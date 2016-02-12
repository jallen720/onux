#include "tests/utils/expectNoThrow.hpp"

#include <iostream>
#include <exception>
#include <gtest/gtest.h>

using std::cerr;
using std::exception;
using std::function;

void expectNoThrow(const function<void()>& block) {
    try {
        block();
    }
    catch (const exception& e) {
        cerr << "std::exception thrown in test:\n  " << e.what() << "\n";
        FAIL();
    }
    catch (...) {
        cerr << "Unknown exception thrown in test!\n";
        FAIL();
    }
}
