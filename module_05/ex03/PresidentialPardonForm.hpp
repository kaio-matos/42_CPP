/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:59:04 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/16 19:58:40 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &value);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &value);
    ~PresidentialPardonForm(void);

    void execute(Bureaucrat const &executor) const;

    std::string target;
};
