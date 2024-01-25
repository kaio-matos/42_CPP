/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/24 21:57:44 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iomanip>
#include <iostream>

class ClapTrap {
    public:
        static ClapTrap   *clap_traps[20];
        static int        clap_traps_length;
        static ClapTrap          *getClapTrap(const std::string name);

        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &value);
        ClapTrap& operator=(const ClapTrap &value);
        ~ClapTrap(void);

        void              attack(const std::string& target);
        void              takeDamage(unsigned int amount);
        void              beRepaired(unsigned int amount);
        void              log(void);

        std::string       getName(void) const;
        void              setDamage(unsigned int amount);

    protected:
        std::string       __instance_name;
        std::string       name;
        int               hit_points;
        int               energy_points;
        int               attack_damage;
        bool              canAct(std::string action);
        void              consumeEnergy(unsigned int amount = 1);

        void              appendClapTrap(ClapTrap *clap_trap);
        void              removeClapTrap(ClapTrap *clap_trap);
};

#endif
