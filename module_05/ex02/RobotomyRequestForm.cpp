/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:59:04 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/21 20:58:17 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(
    std::string target) : AForm("Robotomy Request Form", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &value) : AForm(value.getName(), value.getGradeToSign(), value.getGradeToExecute()), target(value.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    AForm::operator=(rhs);
    *this = rhs;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    try
    {

        this->validateExecution(executor);
        std::cout << "Buzzzzz... Zzzip! Zzzip! Clank! Clank! Whirrrr....\n"
                  << this->target
                  << " has been robotomized successfully 50% of the time."
                  << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Robotomy failed, because " << e.what() << std::endl;
        throw;
    }
};
