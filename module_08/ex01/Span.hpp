/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:36:30 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/29 19:52:35 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include <iostream>

class Span {
public:
	Span(void);
	~Span(void);
	Span(unsigned int n);
	Span(const Span &value);
	Span &operator=(const Span &value);

	size_t getSize(void) const;

	void         addNumber(int n);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);

	template <typename T>
	void addRange(T begin, T end) {
		unsigned int space = this->_max - this->_array.size();

		if (std::distance(begin, end) > space)
			throw std::runtime_error("Not enough capacity");
		while (begin != end) {
			this->addNumber(*begin);
			begin++;
		}
	}

private:
	std::vector<int> _array;
	unsigned int     _max;
};

#endif
