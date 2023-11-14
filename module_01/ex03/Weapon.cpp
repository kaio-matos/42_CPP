/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:43:12 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/13 21:28:54 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <ostream>
#include <iostream>

Weapon::Weapon(std::string type): type(type) {}
Weapon::Weapon(void) {}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType() {
    return this->type;
}

void Weapon::setType(std::string type) {
    this->type = type;
}


