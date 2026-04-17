#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isCharLiteral(const std::string &s) {
	return s.length() == 1 && !std::isdigit(s[0]);
}

static bool isPseudoLiteral(const std::string &s) {
	return s == "nan" || s == "nanf"
		|| s == "+inf" || s == "+inff"
		|| s == "-inf" || s == "-inff"
		|| s == "inf" || s == "inff";
}

static bool isFloatLiteral(const std::string &s) {
	if (s.empty() || s[s.length() - 1] != 'f')
		return false;
	std::string tmp = s.substr(0, s.length() - 1);
	if (tmp.empty())
		return false;
	char *end;
	std::strtod(tmp.c_str(), &end);
	return *end == '\0' && tmp.find('.') != std::string::npos;
}

static bool isDoubleLiteral(const std::string &s) {
	if (s.empty())
		return false;
	char *end;
	std::strtod(s.c_str(), &end);
	return *end == '\0' && s.find('.') != std::string::npos;
}

static bool isIntLiteral(const std::string &s) {
	if (s.empty())
		return false;
	size_t i = 0;
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	if (i == s.length())
		return false;
	for (; i < s.length(); i++) {
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}


void ScalarConverter::convert(const std::string &literal) {
	double d;
	bool impossible = false;

	if (isCharLiteral(literal)) {
		d = static_cast<double>(literal[0]);
	} else if (isPseudoLiteral(literal)) {
		if (literal == "nanf" || literal == "nan")
			d = std::strtod("nan", NULL);
		else if (literal == "+inff" || literal == "+inf" || literal == "inff" || literal == "inf")
			d = std::strtod("inf", NULL);
		else
			d = std::strtod("-inf", NULL);
	} else if (isIntLiteral(literal)) {
		long l = std::strtol(literal.c_str(), NULL, 10);
		d = static_cast<double>(l);
	} else if (isFloatLiteral(literal)) {
		std::string tmp = literal.substr(0, literal.length() - 1);
		d = std::strtod(tmp.c_str(), NULL);
	} else if (isDoubleLiteral(literal)) {
		d = std::strtod(literal.c_str(), NULL);
	} else {
		impossible = true;
		d = 0;
	}

	printChar(d, impossible);
	printInt(d, impossible);
	printFloat(d, impossible);
	printDouble(d, impossible);
}
