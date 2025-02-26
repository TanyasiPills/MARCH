#pragma once

#include <iostream>

#define Log(x) std::cout << x << std::endl
#define LogError(type,line,ne) std::cerr << type << " error at line " << line << ": " << ne << std::endl
