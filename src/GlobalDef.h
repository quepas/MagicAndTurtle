#pragma once

#include <cmath>
#include <string>

// common types
typedef signed char	int8;
typedef signed short int16;
typedef signed int int32;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef float float32;

double _round(double val);

#define ENUM_TO_STR(label) std::string() + #label