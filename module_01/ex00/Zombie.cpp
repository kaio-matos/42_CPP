/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:43:12 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/09 19:28:07 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): name(name) {}

Zombie::~Zombie(void) {
    std::cout << this->name << " Destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}


