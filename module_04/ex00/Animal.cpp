/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/16 20:52:29 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Contructed Animal" << std::endl;
}

Animal::Animal(const Animal &value) {
    this->type = value.type;
    std::cout << "Copy Constructor Animal" << std::endl;
}

Animal& Animal::operator=(const Animal &value) {
    this->type = value.getType();
    std::cout << "Assignment Operator Animal" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Destroyed Animal" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "~~~~ unrecognizable sounds ~~~~" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
