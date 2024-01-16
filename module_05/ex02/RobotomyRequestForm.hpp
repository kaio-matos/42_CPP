/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:59:04 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/16 19:58:45 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &value);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &value);
    ~RobotomyRequestForm(void);

    void execute(Bureaucrat const &executor) const;
    std::string target;
};
