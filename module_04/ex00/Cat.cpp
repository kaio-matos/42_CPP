/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/14 20:33:27 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() {
    this->type = "Cat";
    std::cout << "Contructed Cat" << std::endl;
}

Cat::Cat(const Cat &value): Animal() {
    this->type = value.type;
}

Cat& Cat::operator=(const Cat &value) {
    this->type = value.getType();
    return *this;
}

Cat::~Cat() {
    std::cout << "Destroyed Cat" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miau, Miau, Miau" << std::endl;
}
