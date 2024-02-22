/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/21 20:18:47 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &value);
    Form &operator=(const Form &value);
    ~Form(void);

    void beSigned(Bureaucrat bureaucrat);

    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual char const *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual char const *what() const throw();
    };

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

    static int _validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, const Form &dt);

#endif
