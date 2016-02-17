#pragma once

#include <functional>

void expectNoThrow(const std::function<void()>& block);
