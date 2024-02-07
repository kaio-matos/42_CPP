/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/06 21:16:37 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

#include "Span.hpp"

int main()
{
	Span pdfSpan = Span(5);
	pdfSpan.addNumber(6);
	pdfSpan.addNumber(3);
	pdfSpan.addNumber(17);
	pdfSpan.addNumber(9);
	pdfSpan.addNumber(11);
	std::cout << "pdfSpan: " << std::endl;
	std::cout << "Shortest span: " << pdfSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << pdfSpan.longestSpan() << std::endl;

	std::cout << "----------------------" << std::endl;

	Span mySpan = Span(5);
	mySpan.addNumber(1);
	mySpan.addNumber(0);
	mySpan.addNumber(0);
	mySpan.addNumber(0);
	mySpan.addNumber(2);
	std::cout << "mySpan: " << std::endl;
	std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;

	std::cout << "----------------------" << std::endl;

	Span bigSpan = Span(50000);
	std::list<int> test(50000, 0);
  	bigSpan.addRange(test.begin(), test.end());
	std::cout << "bigSpan: " << std::endl;
	std::cout << "Span size: " << bigSpan.getSize() << "\n";
	std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;


	std::cout << "----------------------" << std::endl;

	// Span errorSpan = Span(1);
	// errorSpan.addNumber(1);

	// // not enough capacity
	// errorSpan.addNumber(2);

	// // insufficient elements
	// errorSpan.shortestSpan();
}
