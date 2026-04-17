#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <cmath>

void ScalarConverter::printChar(double d, bool impossible) {
	std::cout << "char: ";
	if (impossible || d != d || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

void ScalarConverter::printInt(double d, bool impossible) {
	std::cout << "int: ";
	if (impossible || d != d || d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

void ScalarConverter::printFloat(double d, bool impossible) {
	std::cout << "float: ";
	if (impossible) {
		std::cout << "impossible" << std::endl;
		return;
	}
	float f = static_cast<float>(d);
	std::cout << f;
	if (!std::isinf(f) && !std::isnan(f) && std::floor(f) == f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double d, bool impossible) {
	std::cout << "double: ";
	if (impossible) {
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << d;
	if (!std::isinf(d) && !std::isnan(d) && std::floor(d) == d)
		std::cout << ".0";
	std::cout << std::endl;
}
