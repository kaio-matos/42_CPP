/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:26:22 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/24 22:25:41 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    this->__instance_name = "ScavTrap";
    this->is_guarding_gate = false;
    std::cout << "ScavTrap " << this->name << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &value): ClapTrap(value) {
    this->hit_points = value.hit_points;
    this->energy_points = value.energy_points;
    this->attack_damage = value.attack_damage;
    this->__instance_name = "ScavTrap";
    std::cout << "ScavTrap " << this->name << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
        this->__instance_name = "ScavTrap";
    }
    std::cout << "ScavTrap " << this->name << " copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (this->name == target) return ;
    if (!this->canAct(std::string("attack ").append(target))) return ;

    ClapTrap *found = ClapTrap::getClapTrap(target);
    if (!found) return;

    std::cout << this->__instance_name << " " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;

    found->takeDamage(this->attack_damage);
    this->consumeEnergy();
}

void ScavTrap::guardGate() {
    if (!this->canAct("guard gate")) return ;

    if (this->is_guarding_gate) {
        std::cout << this->__instance_name << " " << this->name << " is already guarding gate!" << std::endl;
        return ;
    }

    this->is_guarding_gate = true;
    std::cout << this->__instance_name << " " << this->name << " is now in Gate keeper mode." << std::endl;
    this->consumeEnergy();
}

