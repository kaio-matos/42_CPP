/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:26:22 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/24 22:26:23 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name): ClapTrap(name) {
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    this->__instance_name = "FragTrap";
    std::cout << "FragTrap " << this->name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &value): ClapTrap(value) {
    this->hit_points = value.hit_points;
    this->energy_points = value.energy_points;
    this->attack_damage = value.attack_damage;
    this->__instance_name = "FragTrap";
    std::cout << "FragTrap " << this->name << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
        this->__instance_name = "FragTrap";
    }
    std::cout << "FragTrap " << this->name << " copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    if (!this->canAct("high five")) return ;

	std::cout << this->__instance_name << " " << this->name << " Let's high five guys!?!?!!!" << std::endl;
    this->consumeEnergy();
}

