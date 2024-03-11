/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/07 20:54:23 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H
#include <cstddef>
#include <iostream>

template<typename T, typename F>
void iter(T *array, size_t length, F callback) {
	for (size_t i = 0; i < length; i++) {
		callback(array[i]);
	}
}

template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}


#endif
