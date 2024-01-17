/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/16 21:54:26 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat President("President", 1);
	Intern someRandomIntern;
	AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Felix");
	AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *scf = someRandomIntern.makeForm("shrubbery creation", "Home");

	std::cout << "----------------\n"
			  << std::endl;
	President.signForm(*ppf);
	President.executeForm(*ppf);
	std::cout << "----------------\n"
			  << std::endl;

	delete ppf;
	delete rrf;
	delete scf;

	try
	{
		AForm *unexistent = someRandomIntern.makeForm("unexistent form", "Bender");
		std::cout << *unexistent << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
