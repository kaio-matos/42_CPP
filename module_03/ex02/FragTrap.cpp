/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:26:22 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/12/15 21:26:36 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name): ClapTrap(name) {
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    this->__instance_name = "FragTrap";
    std::cout << "FragTrap" << " " << this->name << " instantiated" << std::endl;
}

FragTrap::FragTrap(const FragTrap &value): ClapTrap(value) {
    this->hit_points = value.hit_points;
    this->energy_points = value.energy_points;
    this->attack_damage = value.attack_damage;
    this->__instance_name = "FragTrap";
}

FragTrap& FragTrap::operator=(const FragTrap &rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
    }
    return *this;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap" << " " << this->name  << " instance destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    if (!this->canAct()) {
        if (this->isDead()) {
            std::cout << this->__instance_name << " " << this->name << " tries to high five, but he notices that he is already dead!" << std::endl;
        } else if (this->isOutOfEnergy()) {
            std::cout << this->__instance_name << " " << this->name << " tries to high five, but he notices that he is out of energy!" << std::endl;
        }
        return ;
    }

	std::cout << this->__instance_name << " " << this->name << " Let's high five guys!?!?!!!" << std::endl;
    this->consumeEnergy();
}

