/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/06 20:36:13 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <limits>

class ScalarConverter
{
private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &value);
    ScalarConverter &operator=(const ScalarConverter &value);
    ~ScalarConverter(void);
    enum Types {
        TYPES_INTEGER,
        TYPES_CHAR,
        TYPES_FLOAT,
        TYPES_DOUBLE,
        TYPES_PSEUDO_LITERAL,
        TYPES_INVALID
    };
    static Types getType(std::string type);
    static void printChar(char c, std::string str);
    static void printInt(int i, std::string str);
    static void printFloat(float f, Types type);
    static void printDouble(double d, Types type);

    static bool isFloat(const std::string &string);
    static bool isInt(const std::string &string);
    static bool isDouble(const std::string &string);
    static bool isPseudo(const std::string &string);


public:
    static void convert(std::string string);
};

#endif
