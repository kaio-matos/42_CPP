/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/21 20:57:07 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _bits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value) {
    std::cout << "Copy constructor called" << std::endl;
    this->_bits = value.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &value) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &value) {
        this->_bits = value.getRawBits();
    }
    return *this;
}

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_bits;
};

void    Fixed::setRawBits(int const raw) {
    this->_bits = raw;
};
