/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/09 22:15:17 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string expression) {
	std::string::iterator it = expression.begin();
	std::stack<int> numbers;
	int result = 0;
	bool error = false;

	for (; it != expression.end(); it++) {
		if (*it == ' ') continue ;

		if (std::isdigit(*it)) {
			std::string str_number;
			while (std::isdigit(*it)) {
				str_number += *it;
				it++;
			}

			int number = std::atoi(str_number.c_str());
			numbers.push(number);
			continue ;
		}

		char c = *it;

		if (c == '*' || c == '+' || c == '-' || c == '/') {
			int first = numbers.top();
			numbers.pop();

			if (!numbers.empty()) {
				int second = numbers.top();
				numbers.pop();
				if (c == '+') result = second + first;
				if (c == '-') result = second - first;
				if (c == '/') result = second / first;
				if (c == '*') result = second * first;
				// std::cout << "[OPERATION][" << c << "] " << second << " " << c << " " << first << " = " << result << std::endl;
			}
			numbers.push(result);
			continue ;
		}

		error = true;
		break;
	}
	if (error)
		std::cout << "Error" << std::endl;
	else
		std::cout << result << std::endl;
}

RPN::RPN(const RPN &value) {
	*this = value;
}

RPN &RPN::operator=(const RPN &value) {
	*this = value;
	return *this;
}

RPN::~RPN(void) {}

