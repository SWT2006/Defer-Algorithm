#pragma once
#include "Module.h"
#include "Net.h"
#include <vector>

int computeHPWL(const std::vector<Module>& modules, const std::vector<Net>& nets);
