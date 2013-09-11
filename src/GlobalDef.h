#pragma once

#include <cmath>
#include <string>
#include <sstream>
#include <PolyString.h>

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
#define ENUM_TO_LOWER_STR(label) Polycode::String(#label).toLowerCase()

template <typename typeOutput, typename typeInput>
typeOutput lexical_cast(typeInput typeIn)
{
	std::stringstream strStreamInterpreter;
	typeOutput typeOut;

	strStreamInterpreter << typeIn;
	strStreamInterpreter >> typeOut;

	return typeOut;
};