/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/14 20:33:58 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "Contructed WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &value): WrongAnimal() {
    this->type = value.type;
}

WrongCat& WrongCat::operator=(const WrongCat &value) {
    this->type = value.getType();
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destroyed WrongCat" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Miau, Miau, Miau" << std::endl;
}
