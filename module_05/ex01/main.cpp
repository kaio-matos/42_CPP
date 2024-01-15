/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/15 20:32:04 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void TestFormConstructorTooHighGradeToSign()
{
	std::cout << "TestFormConstructorTooHighGradeToSign" << std::endl;
	try
	{
		Form AnyForm("AnyForm", -3, 2);
		std::cout << AnyForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
void TestFormConstructorTooLowGradeToSign()
{
	std::cout << "TestFormConstructorTooLowGradeToSign" << std::endl;
	try
	{
		Form AnyForm("AnyForm", 151, 2);
		std::cout << AnyForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TestFormConstructorTooHighGradeToExecute()
{
	std::cout << "TestFormConstructorTooHighGradeToExecute" << std::endl;
	try
	{
		Form AnyForm("AnyForm", 3, -4);
		std::cout << AnyForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
void TestFormConstructorTooLowGradeToExecute()
{
	std::cout << "TestFormConstructorTooLowGradeToExecute" << std::endl;
	try
	{
		Form AnyForm("AnyForm", 142, 167);
		std::cout << AnyForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TestBureaucratConstructorTooHighGrade()
{
	std::cout << "TestBureaucratConstructorTooHighGrade" << std::endl;

	try
	{
		Bureaucrat joao("Joao", -3);
		std::cout << joao << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
void TestBureaucratConstructorTooLowGrade()
{
	std::cout << "TestBureaucratConstructorTooLowGrade" << std::endl;

	try
	{
		Bureaucrat joao("Joao", 151);
		std::cout << joao << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "---------------" << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "Should be able to sign" << std::endl;
	Bureaucrat john("John", 20);
	Form ApprovalLawForm("Approval Law", 20, 20);

	john.signForm(ApprovalLawForm);

	std::cout << "---------------" << std::endl;
	std::cout << "---------------" << std::endl;

	std::cout << "Should not be able to sign" << std::endl;
	Bureaucrat felipe("Felipe", 16);
	Form DisapprovalLawForm("Disapproval Law", 15, 20);
	felipe.signForm(DisapprovalLawForm);

	std::cout << "---------------" << std::endl;
	std::cout << "---------------" << std::endl;

	TestBureaucratConstructorTooHighGrade();
	std::cout << "---------------" << std::endl;
	TestBureaucratConstructorTooLowGrade();

	std::cout << "---------------" << std::endl;
	std::cout << "---------------" << std::endl;

	TestFormConstructorTooHighGradeToSign();
	std::cout << "---------------" << std::endl;
	TestFormConstructorTooLowGradeToSign();

	std::cout << "---------------" << std::endl;
	std::cout << "---------------" << std::endl;

	TestFormConstructorTooHighGradeToExecute();
	std::cout << "---------------" << std::endl;
	TestFormConstructorTooLowGradeToExecute();

	std::cout << "---------------" << std::endl;
	std::cout << "---------------" << std::endl;

	return 0;
}
