#pragma once

#include <iostream>

#define Log(x) std::cout << x << std::endl;
#define LogError(x,y,z) std::cerr << x << " error at line " << y << ": " << z << std::endl;
