/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:21:49 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/16 21:26:20 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Contructed Dog" << std::endl;
}

Dog::Dog(const Dog &value): Animal(value) {
    this->type = value.type;
    this->brain = new Brain(*value.brain);
}

Dog& Dog::operator=(const Dog &value) {
    Animal::operator=(value);
    delete this->brain;
    this->brain = new Brain(*value.brain);
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Destroyed Dog" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Au, Au, Au" << std::endl;
}

Brain& Dog::getBrain() const {
    return *(this->brain);
}
