#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>

class ScalarConverter {
private:

	// 正規表現
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static void printChar(double d, bool impossible);
	static void printInt(double d, bool impossible);
	static void printFloat(double d, bool impossible);
	static void printDouble(double d, bool impossible);

public:
	static void convert(const std::string &literal);
};

#endif
