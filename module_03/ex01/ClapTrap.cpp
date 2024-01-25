/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/24 22:16:48 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int       ClapTrap::clap_traps_length = 0;
ClapTrap  *ClapTrap::clap_traps[];

ClapTrap::ClapTrap(std::string name):
    __instance_name("ClapTrap"),
    name(name),
    hit_points(10),
    energy_points(10),
    attack_damage(0)
{
    ClapTrap::appendClapTrap(this);
    std::cout << "ClapTrap " << this->name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &value):
    __instance_name("ClapTrap"),
    name(value.name),
    hit_points(value.hit_points),
    energy_points(value.energy_points),
    attack_damage(value.attack_damage) {
    ClapTrap::appendClapTrap(this);
    std::cout << "ClapTrap " << this->name << " copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        this->attack_damage = rhs.attack_damage;
        this->energy_points = rhs.energy_points;
        this->hit_points = rhs.hit_points;
        ClapTrap::appendClapTrap(this);
    }
    std::cout << "ClapTrap " << this->name << " copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(void) {
    this->removeClapTrap(this);
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (this->name == target) return ;
    if (!this->canAct(std::string("attack ").append(target))) return ;

    ClapTrap *found = ClapTrap::getClapTrap(target);
    if (!found) return;

    std::cout << this->__instance_name << " " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;

    found->takeDamage(this->attack_damage);
    this->consumeEnergy();
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->hit_points -= amount;
    if (this->hit_points < 0) {
        this->hit_points = 0;
        return ;
    }
    std::cout << this->__instance_name << " " << this->name << " received " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!this->canAct("repair itself")) return ;

    this->hit_points += amount;
    if (this->hit_points > 10) {
        this->hit_points = 10;
        return ;
    }
    this->consumeEnergy();
    std::cout << this->__instance_name << " " << this->name << " repaired " << amount << " points of health!" << std::endl;
}

void ClapTrap::log(void) {
    std::cout << std::endl;
    std::cout << "----------------------"<< std::endl;
    std::cout << this->name << " Stats" << std::endl;
    std::cout << "Health -------- " << this->hit_points << std::endl;
    std::cout << "Energy -------- " << this->energy_points << std::endl;
    std::cout << "Attack Damage - " << this->attack_damage << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << std::endl;
}

std::string ClapTrap::getName(void) const {
    return this->name;
}

void ClapTrap::setDamage(unsigned int amount) {
    this->attack_damage = amount;
}

bool ClapTrap::canAct(std::string action) {
    bool isDead = this->hit_points == 0;
    bool isOutOfEnergy = this->energy_points == 0;
    if (isDead) {
        std::cout << this->name << " tries to " << action << ", but he notices that he is dead!" << std::endl;
        return false;
    }
    if (isOutOfEnergy) {
        std::cout << this->name << " tries to " << action << ", but he notices that he is out of energy!" << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::consumeEnergy(unsigned int amount) {
    this->energy_points -= amount;
    if (this->energy_points < 0) {
        this->energy_points = 0;
    }
}

void ClapTrap::appendClapTrap(ClapTrap *clap_trap) {
    ClapTrap::clap_traps[ClapTrap::clap_traps_length] = clap_trap;
    ClapTrap::clap_traps_length += 1;
}

void ClapTrap::removeClapTrap(ClapTrap *clap_trap) {
    for (int i = 0; i < ClapTrap::clap_traps_length; i++) {
        if (ClapTrap::clap_traps[i]->getName() == clap_trap->getName()) {

            for (; i < ClapTrap::clap_traps_length; i++) {
                if (i + 1 < ClapTrap::clap_traps_length) {
                    ClapTrap::clap_traps[i] = ClapTrap::clap_traps[i + 1];
                    ClapTrap::clap_traps[i + 1] = NULL;
                    ClapTrap::clap_traps_length -= 1;
                } else {
                    ClapTrap::clap_traps[i] = NULL;
                    ClapTrap::clap_traps_length -= 1;
                }
            }

            break ;
        }
    }
}

ClapTrap* ClapTrap::getClapTrap(const std::string name) {
    for (int i = 0; i < ClapTrap::clap_traps_length; i++) {
        ClapTrap *clap_trap = ClapTrap::clap_traps[i];

        if (clap_trap->getName() == name) {
            return clap_trap;
        }
    }
    std::cout << "Couldn't find " << name << " " << "!" << std::endl;
    return NULL;
}
