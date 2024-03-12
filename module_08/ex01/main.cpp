/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/11 21:30:29 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstddef>
#include <exception>

int main()
{
	std::srand(std::time(NULL));

	Span pdfSpan = Span(5);
	pdfSpan.addNumber(6);
	pdfSpan.addNumber(3);
	pdfSpan.addNumber(17);
	pdfSpan.addNumber(9);
	pdfSpan.addNumber(11);
	std::cout << "pdfSpan: " << std::endl;
	std::cout << "Shortest span: " << pdfSpan.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << pdfSpan.longestSpan() << std::endl;

	std::cout << "----------------------" << std::endl;

	Span smallSpan = Span(5);
	smallSpan.addNumber(1);
	smallSpan.addNumber(0);
	smallSpan.addNumber(0);
	smallSpan.addNumber(0);
	smallSpan.addNumber(2);
	std::cout << "smallSpan: " << std::endl;
	std::cout << "Shortest span: " << smallSpan.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << smallSpan.longestSpan() << std::endl;

	std::cout << "----------------------" << std::endl;

	Span bigEmptySpan = Span(50000);
	std::list<int> testEmpty(50000, 0);
  	bigEmptySpan.addRange(testEmpty.begin(), testEmpty.end());
	std::cout << "bigEmptySpan: " << std::endl;
	std::cout << "Span size:     " << bigEmptySpan.getSize() << "\n";
	std::cout << "Shortest span: " << bigEmptySpan.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << bigEmptySpan.longestSpan() << std::endl;

	std::cout << "----------------------" << std::endl;

	Span bigSpan = Span(10000);

	std::vector<int> testRandom(10000, 1);
	std::generate(testRandom.begin(), testRandom.end(), std::rand);
  	bigSpan.addRange(testRandom.begin(), testRandom.end());
	std::cout << "bigSpan: " << std::endl;
	std::cout << "Span size:     " << bigSpan.getSize() << "\n";
	std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << bigSpan.longestSpan() << std::endl;

	std::cout << "----------------------" << std::endl;

	Span errorSpan = Span(1);
	errorSpan.addNumber(1);
	// not enough capacity
	try {
		errorSpan.addNumber(2);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	// insufficient elements
	try {
		errorSpan.shortestSpan();
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
