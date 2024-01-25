/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/24 22:10:56 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int       ClapTrap::clap_traps_length = 0;
ClapTrap  *ClapTrap::clap_traps[];

ClapTrap::ClapTrap(std::string name):
    _name(name),
    _hit_points(10),
    _energy_points(10),
    _attack_damage(0)
{
    ClapTrap::_appendClapTrap(this);
    std::cout << "ClapTrap " << this->_name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &value):
    _name(value._name),
    _hit_points(value._hit_points),
    _energy_points(value._energy_points),
    _attack_damage(value._attack_damage) {
    ClapTrap::_appendClapTrap(this);
    std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_attack_damage = rhs._attack_damage;
        this->_energy_points = rhs._energy_points;
        this->_hit_points = rhs._hit_points;
        ClapTrap::_appendClapTrap(this);
    }
    std::cout << "ClapTrap " << this->_name << " copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(void) {
    this->_removeClapTrap(this);
    std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (this->_name == target) return ;
    if (!this->_canAct(std::string("attack ").append(target))) return ;

    ClapTrap *found = ClapTrap::_getClapTrap(target);
    if (!found) return;

    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;

    found->takeDamage(this->_attack_damage);
    this->_consumeEnergy();
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->_hit_points -= amount;
    if (this->_hit_points < 0) {
        this->_hit_points = 0;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " received " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!this->_canAct("repair itself")) {
        return ;
    }

    this->_hit_points += amount;
    if (this->_hit_points > 10) {
        this->_hit_points = 10;
        return ;
    }
    this->_consumeEnergy();
    std::cout << "ClapTrap " << this->_name << " repaired " << amount << " points of health!" << std::endl;
}

void ClapTrap::log(void) {
    std::cout << std::endl;
    std::cout << "----------------------"<< std::endl;
    std::cout << this->_name << " Stats" << std::endl;
    std::cout << "Health -------- " << this->_hit_points << std::endl;
    std::cout << "Energy -------- " << this->_energy_points << std::endl;
    std::cout << "Attack Damage - " << this->_attack_damage << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << std::endl;
}

std::string ClapTrap::getName(void) {
    return this->_name;
}

void ClapTrap::setDamage(unsigned int amount) {
    this->_attack_damage = amount;
}

bool ClapTrap::_canAct(std::string action) {
    bool isDead = this->_hit_points == 0;
    bool isOutOfEnergy = this->_energy_points == 0;
    if (isDead) {
        std::cout << "ClapTrap " << this->_name << " tries to " << action << ", but he notices that he is dead!" << std::endl;
        return false;
    }
    if (isOutOfEnergy) {
        std::cout << "ClapTrap " << this->_name << " tries to " << action << ", but he notices that he is out of energy!" << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::_consumeEnergy(unsigned int amount) {
    this->_energy_points -= amount;
    if (this->_energy_points < 0) {
        this->_energy_points = 0;
    }
}

void ClapTrap::_appendClapTrap(ClapTrap *clap_trap) {
    ClapTrap::clap_traps[ClapTrap::clap_traps_length] = clap_trap;
    ClapTrap::clap_traps_length += 1;
}

void ClapTrap::_removeClapTrap(ClapTrap *clap_trap) {
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

ClapTrap* ClapTrap::_getClapTrap(const std::string name) {
    for (int i = 0; i < ClapTrap::clap_traps_length; i++) {
        ClapTrap *clap_trap = ClapTrap::clap_traps[i];

        if (clap_trap->getName() == name) {
            return clap_trap;
        }
    }
    std::cout << "ClapTrap " << this->_name << " couldn't find ClapTrap " << name << "!" << std::endl;
    return NULL;
}
