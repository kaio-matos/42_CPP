/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/08 20:51:49 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "Contructed WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &value) {
    this->type = value.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &value) {
    this->type = value.getType();
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destroyed WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "~~~~ unrecognizable sounds ~~~~" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
