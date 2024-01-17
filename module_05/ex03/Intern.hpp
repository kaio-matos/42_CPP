/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/16 21:45:53 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"

class Intern
{
public:
    Intern(void);
    Intern(const Intern &value);
    Intern &operator=(const Intern &value);
    ~Intern(void);

    AForm *makeForm(std::string name, std::string target);

    class FormNotFoundException : public std::exception
    {
    public:
        virtual char const *what() const throw();
    };

private:
    AForm *makePresidentialPardonForm(std::string target);
    AForm *makeRobotomyRequestForm(std::string target);
    AForm *makeShrubberyCreationForm(std::string target);
};

#endif
