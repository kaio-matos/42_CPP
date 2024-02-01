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

#define IMPOSSIBLE "impossible";
#define NON_DISPLAYABLE "Non displayable";
#define NOT_A_NUMBER "nan";

std::string toIntegerToStr(std::string string);
std::string toCharToStr(std::string string);
std::string toFloatToStr(std::string string);
std::string toDoubleToStr(std::string string);


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

void ScalarConverter::convert(std::string string) {

	std::string character = toCharToStr(string);
	std::string integer = toIntegerToStr(string);
	std::string floatNumber = toFloatToStr(string);
	std::string doubleNumber = toDoubleToStr(string);


	std::cout
			  << "char: "  << character << "\n"
			  << "int: "   << integer << "\n"
			  << "float: " << floatNumber << "\n"
			  << "double: " << doubleNumber << "\n"
			  << std::endl;
}

std::string toIntegerToStr(std::string string) {
	char* endptr;

	long longInteger = static_cast<long>(std::strtol(string.c_str(), &endptr, 10));

	if (longInteger > std::numeric_limits<int>::max() || longInteger < std::numeric_limits<int>::min()) {
		return IMPOSSIBLE;
	}

	int integer = static_cast<int>(longInteger);

	if (*endptr != '\0' && integer == 0) {
		return IMPOSSIBLE;
	}

	std::ostringstream convert;
	convert << integer;

	return convert.str();
}

std::string toCharToStr(std::string string) {
	char* endptr;
	long longNumber = static_cast<long>(std::strtol(string.c_str(), &endptr, 10));
	char c = static_cast<char>(longNumber);

	if (*endptr != '\0' && longNumber == 0) {
		return IMPOSSIBLE;
	}

	if (longNumber > 255 || longNumber < 0) {
		return IMPOSSIBLE;
	}

	if (std::isprint(c)) {
		std::string result;
		result.append("'");
		result.append(1, c);
		result.append("'");
		return result;
	}
	return NON_DISPLAYABLE;
}

std::string toFloatToStr(std::string string) {
	char* endptr;
	float floatNumber = static_cast<float>(std::strtof(string.c_str(), &endptr));

   	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1);

    if (std::isnan(floatNumber)) {
        oss << NOT_A_NUMBER;
    } else {
        oss << floatNumber ;
    }
	oss << "f";
	return oss.str();
}

std::string toDoubleToStr(std::string string) {
	char* endptr;
	double doubleNumber = static_cast<double>(std::strtod(string.c_str(), &endptr));

   	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1);

    if (std::isnan(doubleNumber)) {
        oss << NOT_A_NUMBER;
    } else {
        oss << doubleNumber;
    }

	return oss.str();
}
