/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/12/08 20:31:55 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iomanip>
#include <iostream>

class Bureaucrat
{
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &value);
    Bureaucrat &operator=(const Bureaucrat &value);
    ~Bureaucrat(void);

    int incrementGrade(void);
    int decrementGrade(void);

    std::string getName(void) const;
    int getGrade(void) const;

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
    int _grade;

    void _validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &dt);

#endif
