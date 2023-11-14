/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:41:31 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/13 21:24:39 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H

#include <iostream>
#include <iomanip>
#include "HumanB.hpp"
#include "Weapon.hpp"

class HumanB {

    public:
        HumanB(std::string name);
        ~HumanB(void);
        void            attack(void);
        void            setWeapon(Weapon &weapon);

    private:
        std::string     name;
        Weapon          *weapon;
};

#endif

