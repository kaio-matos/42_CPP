/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/16 20:44:38 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void TestPresidentialPardonFormGradeTooLowException()
{
	std::cout << "TestPresidentialPardonFormGradeTooLowException\n"
			  << std::endl;
	try
	{
		Bureaucrat Judge("Judge", 100);
		Bureaucrat President("President", 1);
		PresidentialPardonForm PresidentialPardonForm("John");
		President.signForm(PresidentialPardonForm);
		Judge.executeForm(PresidentialPardonForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TestRobotomyRequestFormNotSignedException()
{
	std::cout << "TestRobotomyRequestFormNotSignedException\n"
			  << std::endl;
	try
	{
		Bureaucrat President("President", 1);
		RobotomyRequestForm RobotomyRequestForm("Luiz");
		President.executeForm(RobotomyRequestForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void TestRobotomyRequestFormExecution()
{
	std::cout << "TestRobotomyRequestFormExecution\n"
			  << std::endl;
	Bureaucrat President("President", 1);
	RobotomyRequestForm RobotomyRequestForm("Felipe");
	President.signForm(RobotomyRequestForm);
	President.executeForm(RobotomyRequestForm);
}
void TestPresidentialPardonFormExecution()
{
	std::cout << "TestPresidentialPardonFormExecution\n"
			  << std::endl;
	Bureaucrat President("President", 1);
	PresidentialPardonForm PresidentialPardonForm("Mateus");
	President.signForm(PresidentialPardonForm);
	President.executeForm(PresidentialPardonForm);
}

void TestShrubberyCreationFormExecution()
{
	std::cout << "TestShrubberyCreationFormExecution\n"
			  << std::endl;
	Bureaucrat President("President", 1);
	ShrubberyCreationForm ShrubberyCreationForm("Home");
	President.signForm(ShrubberyCreationForm);
	President.executeForm(ShrubberyCreationForm);
}

int main(void)
{
	std::cout << "\n\n\n\n"
			  << std::endl;

	std::cout << "-----------------------------------------" << std::endl;
	TestPresidentialPardonFormGradeTooLowException();
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	TestRobotomyRequestFormNotSignedException();
	std::cout << "-----------------------------------------" << std::endl;

	std::cout << "\n\n\n\n"
			  << std::endl;

	std::cout << "-----------------------------------------" << std::endl;
	TestRobotomyRequestFormExecution();
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	TestPresidentialPardonFormExecution();
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	TestShrubberyCreationFormExecution();
	return 0;
}
