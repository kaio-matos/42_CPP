/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/14 20:37:06 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Contructed Cat" << std::endl;
}

Cat::Cat(const Cat &value): Animal() {
    this->type = value.type;
    this->brain = new Brain(*value.brain);
}

Cat& Cat::operator=(const Cat &value) {
    this->type = value.getType();
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
