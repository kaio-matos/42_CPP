/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:43:12 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/18 20:53:28 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <ostream>
#include <iostream>

Weapon::Weapon(std::string type): _type(type) {}
Weapon::Weapon(void) {}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType() {
    return this->_type;
}

void Weapon::setType(std::string type) {
    this->_type = type;
}


