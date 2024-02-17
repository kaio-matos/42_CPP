/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/16 21:13:23 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "Contructed WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &value): WrongAnimal() {
    this->type = value.type;
    std::cout << "Copy Constructor WrongCat" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &value) {
    WrongAnimal::operator=(value);
    std::cout << "Assignment Operator WrongCat" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destroyed WrongCat" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Miau, Miau, Miau" << std::endl;
}
