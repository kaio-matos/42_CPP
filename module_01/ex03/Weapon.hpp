/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:41:31 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/13 20:24:18 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iomanip>
#include "Weapon.hpp"

class Weapon {

    public:
        Weapon(std::string type);
        Weapon(void);
        ~Weapon(void);
        const std::string       &getType();
        void                    setType(std::string type);

    private:
        std::string type;
};

#endif

