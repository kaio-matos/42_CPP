/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:59:04 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/16 19:58:48 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &value);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &value);
    ~ShrubberyCreationForm(void);

    void execute(Bureaucrat const &executor) const;
    std::string target;
};
