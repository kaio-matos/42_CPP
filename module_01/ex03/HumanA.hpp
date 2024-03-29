/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:41:31 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/18 19:43:51 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <iostream>
#include <iomanip>
#include "Weapon.hpp"

class HumanA {

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void            attack(void);

    private:
        std::string     _name;
        Weapon          &_weapon;
};

#endif

