/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/16 21:09:19 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() {
    this->type = "Cat";
    std::cout << "Contructed Cat" << std::endl;
}

Cat::Cat(const Cat &value): Animal() {
    this->type = value.type;
    std::cout << "Copy Contructor Cat" << std::endl;
}

Cat& Cat::operator=(const Cat &value) {
    Animal::operator=(value);
    std::cout << "Assignment Operator Cat" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Destroyed Cat" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miau, Miau, Miau" << std::endl;
}
