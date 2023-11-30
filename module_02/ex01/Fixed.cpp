/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/29 21:06:16 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(void): _bits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value) {
    std::cout << "Copy constructor called" << std::endl;
    *this = value;
}

Fixed &Fixed::operator=(const Fixed &value) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &value) {
        this->_bits = value.getRawBits();
    }
    return *this;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_bits = value << this->_fractional_bits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;

    float scaled_number = value * static_cast<float>(1 << this->_fractional_bits);
    int fixed_point_number = static_cast<int>(scaled_number);
    this->_bits = fixed_point_number;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const {
    return this->_bits;
};

void    Fixed::setRawBits(int const raw) {
    this->_bits = raw;
};

float   Fixed::toFloat(void) const {
    return this->_bits / static_cast<float>(1 << this->_fractional_bits);
}

int Fixed::toInt(void) const {
    return this->_bits >> this->_fractional_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& value) {
   os << value.toFloat();
   return os;
}
