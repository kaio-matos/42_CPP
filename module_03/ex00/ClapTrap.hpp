/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/24 21:54:49 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iomanip>
#include <iostream>

class ClapTrap {
    public:
        static ClapTrap *clap_traps[20];
        static int      clap_traps_length;

        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &value);
        ClapTrap& operator=(const ClapTrap &value);
        ~ClapTrap(void);

        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        void        log(void);

        std::string getName(void);
        void        setDamage(unsigned int amount);

    private:
        std::string _name;
        int         _hit_points;
        int         _energy_points;
        int         _attack_damage;
        bool        _canAct(std::string action);
        void        _consumeEnergy(unsigned int amount = 1);
        void        _appendClapTrap(ClapTrap *clap_trap);
        void        _removeClapTrap(ClapTrap *clap_trap);
        ClapTrap    *_getClapTrap(const std::string name);
};

#endif
