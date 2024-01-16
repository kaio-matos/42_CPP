/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/16 19:51:49 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAForm_H
#define AAForm_H

#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &value);
    AForm &operator=(const AForm &value);
    ~AForm(void);

    void beSigned(Bureaucrat bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

    void validateExecution(Bureaucrat bureaucrat) const;

    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    friend std::ostream &operator<<(std::ostream &os, const AForm &dt);

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

    class NotSignedException : public std::exception
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

#endif
