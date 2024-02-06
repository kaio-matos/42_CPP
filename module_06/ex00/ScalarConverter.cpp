/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/11 21:57:38 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &value)
{
	*this = value;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	*this = rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter::Types ScalarConverter::getType(std::string string) {
	int dots = 0;
	std::string pseudoLiterals[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};

	for (size_t i = 0; i < 6; i++) {
		if (string == pseudoLiterals[i]) {
			return TYPES_PSEUDO_LITERAL;
		}
	}

	if (string.length() == 1 && !std::isdigit(string[0]))
        return TYPES_CHAR;

	if (string[0] == '+' || string[0] == '-' || std::isdigit(string[0])) {
		bool isNumber = true;

		for (size_t i = 1; i < string.length(); i++) {
			char c = string[i];

			if (i == string.length() - 1 && c == 'f') {}
			else if (c == '.') {
				dots++;
			} else if (!std::isdigit(c) || dots > 1) {
				isNumber = false;
			}
		}

		if (isNumber) {
			if (string.find_first_of('.') != std::string::npos) {
				if (string[string.length() - 1] == 'f') {
					return TYPES_FLOAT;
				}

				return TYPES_DOUBLE;
			}

			return TYPES_INTEGER;
		}
	}

	return TYPES_INVALID;
}


void ScalarConverter::convert(std::string string) {
	if (string.length() == 0) return;

	ScalarConverter::Types type = getType(string);

	switch (type)
	{
	case TYPES_CHAR: {
		char c = static_cast<char>(string.c_str()[0]);

		printChar(c, string);
		printInt(static_cast<int>(c), string);
		printFloat(static_cast<float>(c), type);
		printDouble( static_cast<double>(c), type);
		break;
	}
	case TYPES_INTEGER: {
		int integer = std::atoi(string.c_str());

		printChar(static_cast<char>(integer), string);
		printInt(integer, string);
		printFloat(static_cast<float>(integer), type);
		printDouble(static_cast<double>(integer), type);
		break;
	}
	case TYPES_FLOAT: {
		float f = std::strtof(string.c_str(), NULL);

		printChar(static_cast<char>(f), string);
		printInt(static_cast<int>(f), string);
		printFloat(f, type);
		printDouble( static_cast<double>(f), type);
		break;
	}
	case TYPES_DOUBLE: {
		double d = std::strtod(string.c_str(), NULL);

		printChar(static_cast<char>(d), string);
		printInt(static_cast<int>(d), string);
		printFloat(static_cast<float>(d), type);
		printDouble(d, type);
		break;
	}
	case TYPES_PSEUDO_LITERAL: {
		printPseudo(string);
		break;
	}
	case TYPES_INVALID: {
		std::cout << "Error: Invalid type" << std::endl;
		break;
	}
	}
}

void ScalarConverter::printChar(char c, std::string str)
{
    if (std::atol(str.c_str()) < -128 || std::atol(str.c_str()) > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(int i, std::string str)
{
    if (std::atol(str.c_str()) < std::numeric_limits<int>::min() || std::atol(str.c_str()) > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f, ScalarConverter::Types type)
{
    if ((f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max()) && (type == TYPES_INTEGER))
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d, ScalarConverter::Types type)
{
    if ((d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max()) && (type == TYPES_INTEGER))
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printPseudo(std::string str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nanf" || str == "nan")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inff" || str == "+inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inff" || str == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}
