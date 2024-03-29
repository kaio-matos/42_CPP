/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:36:33 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/11 21:06:27 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _array(std::vector<int>()), _max(0) {}

Span::~Span(void) {}

Span::Span(unsigned int n): _array(std::vector<int>()), _max(n) {}

Span::Span(const Span &value): _array(std::vector<int>(value._array)), _max(value._max) {}

Span &Span::operator=(const Span &value) {
	if (this != &value) {
		this->_array = std::vector<int>(value._array);
		this->_max = value._max;
	}
	return (*this);
}

size_t Span::getSize(void) const {
	return (this->_array.size());
}

void Span::addNumber(int n) {
	if (this->_array.size() == this->_max)
		throw std::runtime_error("Not enough capacity");
	else
		this->_array.push_back(n);
}

unsigned int Span::shortestSpan(void) {
	std::vector<int> copy(this->_array);
	std::vector<int>::iterator it;
	unsigned int span;

	if (this->_array.size() < 2)
		throw std::runtime_error("Insufficient elements");

	std::sort(copy.begin(), copy.end());
	it = copy.begin() + 1;
	span = *it - *(it - 1);
	for (; it != copy.end(); it++) {
		span = std::min(span, static_cast<unsigned int>(*it - *(it - 1)));
	}
	return (span);
}

unsigned int Span::longestSpan(void) {
	if (this->_array.size() < 2)
		throw std::runtime_error("Insufficient elements");
	std::vector<int>::iterator it1 = std::min_element(this->_array.begin(), this->_array.end());
  	std::vector<int>::iterator it2 = std::max_element(this->_array.begin(), this->_array.end());
  	return (*it2 - *it1);
}
