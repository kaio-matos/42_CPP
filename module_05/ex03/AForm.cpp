/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/21 20:20:59 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(
    std::string name,
    int gradeToSign,
    int gradeToExecute) : _name(name),
                          _isSigned(false),
                          _gradeToSign(AForm::_validateGrade(gradeToSign)),
                          _gradeToExecute(AForm::_validateGrade(gradeToExecute))
{
}

AForm::AForm(const AForm &value) : _name(value.getName()),
                                   _isSigned(value.getIsSigned()),
                                   _gradeToSign(value.getGradeToSign()),
                                   _gradeToExecute(value.getGradeToExecute())
{
}

AForm &AForm::operator=(const AForm &rhs)
{
    *this = rhs;
    return *this;
}

AForm::~AForm(void)
{
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeToSign)
        this->_isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

int AForm::_validateGrade(int grade)
{
    if (grade < 1)
        throw AForm::GradeTooHighException();
    else if (grade > 150)
        throw AForm::GradeTooLowException();
    return (grade);
}

void AForm::validateExecution(Bureaucrat bureaucrat) const
{
    if (!this->_isSigned)
        throw AForm::NotSignedException();
    if (bureaucrat.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
};

std::string AForm::getName(void) const
{
    return this->_name;
};
bool AForm::getIsSigned(void) const
{
    return this->_isSigned;
};
int AForm::getGradeToSign(void) const
{
    return this->_gradeToSign;
};
int AForm::getGradeToExecute(void) const
{
    return this->_gradeToExecute;
};

char const *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

char const *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

char const *AForm::NotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &dt)
{
    os << dt.getName()
       << " (AForm with required grade to sign " << dt.getGradeToSign()
       << ", and required grade to execute " << dt.getGradeToExecute();
    if (dt.getIsSigned())
        os << ", that is signed)";
    else
        os << ", that is not signed)";

    return os;
}
