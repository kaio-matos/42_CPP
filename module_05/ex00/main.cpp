/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/11 20:24:36 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void TestIncrementDecrementGrade()
{
	std::cout << "TestIncrementDecrementGrade" << std::endl;
	try
	{
		/* do some stuff with bureaucrats */
		Bureaucrat bureaucrat("John", 75);

		std::cout << "Incrementing Grade" << std::endl;
		bureaucrat.incrementGrade();

		std::cout << "Should be 74 ---> " << bureaucrat.getGrade() << std::endl;

		std::cout << "Decrementing Grade" << std::endl;
		bureaucrat.decrementGrade();

		std::cout << "Should be 75 ---> " << bureaucrat.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		/* should not throw any exception */
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

void TestConstructorTooHighException()
{
	std::cout << "TestConstructorTooHighException" << std::endl;
	try
	{
		Bureaucrat bureaucrat("John", -1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

void TestConstructorTooLowException()
{
	std::cout << "TestConstructorTooLowException" << std::endl;
	try
	{
		Bureaucrat bureaucrat("John", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

void TestIncrementException()
{
	std::cout << "TestIncrementException" << std::endl;
	try
	{
		Bureaucrat bureaucrat("John", 1);
		bureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

void TestDecrementException()
{
	std::cout << "TestDecrementException" << std::endl;
	try
	{
		Bureaucrat bureaucrat("John", 150);
		bureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

void TestPrint()
{
	Bureaucrat bureaucrat("Philip", 150);
	std::cout << "Testing printing: \n"
			  << bureaucrat << std::endl;
	std::cout << "---------------" << std::endl;
}

int main(void)
{
	std::cout << "---------------" << std::endl;
	TestIncrementDecrementGrade();
	TestConstructorTooHighException();
	TestConstructorTooLowException();
	TestIncrementException();
	TestDecrementException();
	TestPrint();
	return 0;
}
