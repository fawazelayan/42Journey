#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cerrno>
#include <cmath>
#include <iomanip>

static void printFloat(float f)
{
	if (f == std::floor(f))
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";
	else
		std::cout << f << "f\n";
	std::cout.unsetf(std::ios::floatfield);
}

static void printDouble(double d)
{
	if (d == std::floor(d))
		std::cout << std::fixed << std::setprecision(1) << d << "\n";
	else
		std::cout << d << "\n";
	std::cout.unsetf(std::ios::floatfield);
}

static void printAll(double d)
{
	bool isNan = (d != d);
	bool isInf = (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity());

	// Char
	std::cout << "char: ";
	if (isNan || isInf || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "impossible\n";
	else
	{
		char c = static_cast<char>(d);
		if (std::isprint(c))
			std::cout << "'" << c << "'\n";
		else
			std::cout << "non-displayable\n";
	}

	// Int
	std::cout << "int: ";
	if (isNan || isInf || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << "\n";

	// Float
	std::cout << "float: ";
	if (isNan)
		std::cout << "nanf\n";
	else if (isInf)
		std::cout << (d < 0 ? "-inff\n" : "inff\n");
	else if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
		std::cout << "impossible\n";
	else
		printFloat(static_cast<float>(d));

	// Double
	std::cout << "double: ";
	if (isNan)
		std::cout << "nan\n";
	else if (isInf)
		std::cout << (d < 0 ? "-inf\n" : "inf\n");
	else
		printDouble(d);
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		printAll(static_cast<double>(literal[0]));
		return;
	}
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		printAll(static_cast<double>(literal[1]));
		return;
	}

	char* endptr;
	errno = 0;
	double val = std::strtod(literal.c_str(), &endptr);

	if (endptr == literal.c_str() || *endptr != '\0')
	{
		if (!((*endptr == 'f' || *endptr == 'F') && *(endptr + 1) == '\0'))
		{
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
			return;
		}
	}

	bool isPseudo = (literal == "nan" || literal == "nanf" ||
					 literal == "inf" || literal == "inff" ||
					 literal == "-inf" || literal == "-inff" ||
					 literal == "+inf" || literal == "+inff");

	bool isFloat = (!isPseudo && (literal.find_first_of("fF") != std::string::npos));
	bool isDouble = (!isPseudo && !isFloat && (literal.find('.') != std::string::npos || literal.find_first_of("eE") != std::string::npos));
	bool isInt = (!isPseudo && !isFloat && !isDouble);

	if (isInt)
	{
		if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min() || errno == ERANGE)
		{
			std::cerr << "Error: int overflow\n";
			return;
		}
	}
	else if (isFloat)
	{
		if (val > std::numeric_limits<float>::max() || val < -std::numeric_limits<float>::max() || errno == ERANGE)
		{
			std::cerr << "Error: float overflow\n";
			return;
		}
	}
	else if (isDouble)
	{
		if (errno == ERANGE)
		{
			std::cerr << "Error: double overflow\n";
			return;
		}
	}

	printAll(val);
}