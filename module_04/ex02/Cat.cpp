/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/16 21:26:11 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Contructed Cat" << std::endl;
}

Cat::Cat(const Cat &value): Animal(value) {
    this->type = value.type;
    this->brain = new Brain(*value.brain);
    std::cout << "Copy Contructor Cat" << std::endl;
}

Cat& Cat::operator=(const Cat &value) {
    Animal::operator=(value);
    delete this->brain;
    this->brain = new Brain(*value.brain);
    std::cout << "Assignment Operator Cat" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Destroyed Cat" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miau, Miau, Miau" << std::endl;
}

Brain& Cat::getBrain() const {
    return *(this->brain);
}
