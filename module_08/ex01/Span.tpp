/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:37:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/06 21:12:22 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename T>
void Span::addRange(T begin, T end) {
	unsigned int space = this->_max - this->_array.size();

	if (std::distance(begin, end) > space)
		throw std::runtime_error("Not enough capacity");
	while (begin != end) {
		this->addNumber(*begin);
		begin++;
 	}
}

#endif
