/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:59:04 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/21 20:58:03 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(
    std::string target) : AForm("Presidential Pardon Form", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &value) : AForm(value.getName(), value.getGradeToSign(), value.getGradeToExecute()), target(value.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    AForm::operator=(rhs);
    *this = rhs;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    this->validateExecution(executor);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};
