/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/12/15 21:28:38 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iomanip>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap &value);
        FragTrap& operator=(const FragTrap &value);
        ~FragTrap(void);

        void highFivesGuys(void);
};

#endif
