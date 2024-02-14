/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:21:49 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/14 20:33:37 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal() {
    this->type = "Dog";
    std::cout << "Contructed Dog" << std::endl;
}

Dog::Dog(const Dog &value): Animal() {
    this->type = value.type;
}

Dog& Dog::operator=(const Dog &value) {
    this->type = value.getType();
    return *this;
}

Dog::~Dog() {
    std::cout << "Destroyed Dog" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Au, Au, Au" << std::endl;
}
