/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/14 19:39:37 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string expression) {
	std::stack<int> numbers;
	int result = 0;
	int number;

	for (std::string::iterator it = expression.begin(); it != expression.end(); it++) {
		if (*it == ' ') continue ;

		if (_getNumber(it, expression.end(), number)) {
			numbers.push(number);
			if (it == expression.end()) {
				result = numbers.top();
				break ;
			}
			continue ;
		}

		char c = *it;

		if (c == '*' || c == '+' || c == '-' || c == '/') {
			int first = numbers.top();
			numbers.pop();

			if (_assert(numbers.empty()))
				return;
			else {
				int second = numbers.top();
				numbers.pop();
				if (c == '+') result = second + first;
				if (c == '-') result = second - first;
				if (c == '/') {
					if (_assert(first == 0)) return;
					result = second / first;
				}
				if (c == '*') result = second * first;
				// std::cout << "[OPERATION][" << c << "] " << second << " " << c << " " << first << " = " << result << std::endl;
			}

			numbers.push(result);
			continue ;
		}
		_assert(true);
		return;
	}
	if (!_assert(numbers.size() > 1))
		std::cout << result << std::endl;
}

RPN::RPN(const RPN &value): _rawExpression(value._rawExpression) {}

RPN &RPN::operator=(const RPN &value) {
	this->_rawExpression = value._rawExpression;
	return *this;
}

RPN::~RPN(void) {}

bool RPN::_assert(bool hasError) const {
	if (hasError) {
		std::cout << "Error" << std::endl;
		return true;
	}
	return false;
}

bool RPN::_getNumber(std::string::iterator &ch, std::string::iterator end, int &value) const {
	std::string str_number = "";

	if ((*ch == '-' || *ch == '+') && std::isdigit(*(ch + 1))) {
		str_number += *ch;
		ch++;
	}

	if (!std::isdigit(*ch)) return false;

	while (ch != end && std::isdigit(*ch)) {
		str_number += *ch;
		ch++;
	}
	value = std::atoi(str_number.c_str());
	return true;
}
