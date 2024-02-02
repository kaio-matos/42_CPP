/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/02 19:13:30 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

template<typename T>
T const &max(T const & a, T const & b) {
    if (a > b) {
        return a;
    } else if (a == b) {
		return b;
	}
    return b;
}

template<typename T>
T const &min(T const & a, T const & b) {
    if (a < b) {
        return a;
    } else if (a == b) {
		return b;
	}
    return b;
}

template<typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}



int main(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	int e = 33;
	int f = 33;
	std::cout << "e address:          " << &e << std::endl;;
	std::cout << "f address:          " << &f << std::endl;;
	std::cout << "Output address max: " << &::max(e, f) << std::endl;;
	std::cout << "Output address min: " << &::min(e, f) << std::endl;;
	return 0;
}
