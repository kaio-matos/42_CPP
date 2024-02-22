/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/21 20:19:03 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(
    std::string name,
    int gradeToSign,
    int gradeToExecute) : _name(name),
                          _isSigned(false),
                          _gradeToSign(Form::_validateGrade(gradeToSign)),
                          _gradeToExecute(Form::_validateGrade(gradeToExecute))
{
}

Form::Form(const Form &value) : _name(value.getName()),
                                _isSigned(value.getIsSigned()),
                                _gradeToSign(value.getGradeToSign()),
                                _gradeToExecute(value.getGradeToExecute())
{
}

Form &Form::operator=(const Form &rhs)
{
    *this = rhs;
    return *this;
}

Form::~Form(void)
{
}

void Form::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeToSign)
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

int Form::_validateGrade(int grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    else if (grade > 150)
        throw Form::GradeTooLowException();
    return (grade);
}

std::string Form::getName(void) const
{
    return this->_name;
};
bool Form::getIsSigned(void) const
{
    return this->_isSigned;
};
int Form::getGradeToSign(void) const
{
    return this->_gradeToSign;
};
int Form::getGradeToExecute(void) const
{
    return this->_gradeToExecute;
};

char const *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

char const *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &dt)
{
    os << dt.getName()
       << " (form with required grade to sign " << dt.getGradeToSign()
       << ", and required grade to execute " << dt.getGradeToExecute();
    if (dt.getIsSigned())
        os << ", that is signed)";
    else
        os << ", that is not signed)";

    return os;
}
