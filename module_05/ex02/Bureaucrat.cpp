/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/21 20:19:46 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->_validateGrade(grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &value) : _name(value.getName()), _grade(value.getGrade())
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	*this = rhs;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
}

int Bureaucrat::incrementGrade(void)
{
	int newGrade = this->_grade - 1;
	this->_validateGrade(newGrade);
	this->_grade = newGrade;
	return (newGrade);
}

int Bureaucrat::decrementGrade(void)
{
	int newGrade = this->_grade + 1;
	this->_validateGrade(newGrade);
	this->_grade = newGrade;
	return (newGrade);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn't sign " << form << " because "
				  << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn't execute " << form << " because "
				  << e.what() << std::endl;
	}
}

void Bureaucrat::_validateGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
};

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
};

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high for a bureaucrat, above 1 (0, -1, -2)";
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low for a bureaucrat, lower than 150 (151, 152, 153)";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &dt)
{
	os << dt.getName() << " (bureaucrat with grade " << dt.getGrade() << ")";
	return os;
}
