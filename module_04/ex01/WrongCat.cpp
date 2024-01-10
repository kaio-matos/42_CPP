/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/08 21:26:57 by kmatos-s         ###   ########.fr       */
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
    *this = value;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destroyed WrongCat" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Miau, Miau, Miau" << std::endl;
}
