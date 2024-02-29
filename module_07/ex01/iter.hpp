/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/28 21:48:23 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H
#include <cstddef>
#include <iostream>

template<typename T>
void iter(T *array, size_t length, void (*callback)(const T &)) {
	for (size_t i = 0; i < length; i++) {
		callback(array[i]);
	}
}

template <typename T>
void print(const T& element) {
    std::cout << element << std::endl;
}


#endif
