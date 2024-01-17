/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:04:16 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/16 21:53:55 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &value)
{
    *this = value;
}

Intern &Intern::operator=(const Intern &rhs)
{
    *this = rhs;
    return *this;
}

Intern::~Intern(void)
{
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    typedef AForm *(Intern::*intern_methods)(std::string target);

    intern_methods methods[3] = {
        &Intern::makePresidentialPardonForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makeShrubberyCreationForm,
    };

    std::string levels[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"};

    for (int i = 0; i < 3; i++)
        if (name == levels[i])
        {
            AForm *form = (this->*methods[i])(target);
            std::cout << "Intern creates " << *form << std::endl;
            return form;
        }

    throw Intern::FormNotFoundException();
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}
AForm *Intern::makeRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}
AForm *Intern::makeShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

char const *Intern::FormNotFoundException::what() const throw()
{
    return "Form was not found";
}
