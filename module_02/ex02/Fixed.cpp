/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/22 22:02:14 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(void): _bits(0) {
}

Fixed::Fixed(const Fixed &value) {
    *this = value;
}

Fixed &Fixed::operator=(const Fixed &value) {
    if (this != &value) {
        this->_bits = value.getRawBits();
    }
    return *this;
}

Fixed::Fixed(const int value) {
    this->_bits = value << this->_fractional_bits;
}

Fixed::Fixed(const float value) {
    float scaled_number = roundf(value * static_cast<float>(1 << this->_fractional_bits));
    int fixed_point_number = static_cast<int>(scaled_number);
    this->_bits = fixed_point_number;
}

Fixed::~Fixed(void) {
}


bool   Fixed::operator>(const Fixed &rhs) {
    return this->toFloat() > rhs.toFloat();
}
bool   Fixed::operator<(const Fixed &rhs) {
    return this->toFloat() < rhs.toFloat();
}
bool   Fixed::operator>=(const Fixed &rhs) {
    return this->toFloat() >= rhs.toFloat();
}
bool   Fixed::operator<=(const Fixed &rhs) {
    return this->toFloat() <= rhs.toFloat();
}
bool   Fixed::operator==(const Fixed &rhs) {
    return this->toFloat() == rhs.toFloat();
}
bool   Fixed::operator!=(const Fixed &rhs) {
    return this->toFloat() != rhs.toFloat();
}

Fixed Fixed::operator+(const Fixed &rhs) {
    Fixed result(this->toFloat() + rhs.toFloat());
    return result;
}
Fixed Fixed::operator-(const Fixed &rhs) {
    Fixed result(this->toFloat() - rhs.toFloat());
    return result;
}
Fixed Fixed::operator*(const Fixed &rhs) {
    Fixed result(this->toFloat() * rhs.toFloat());
    return result;
}
Fixed Fixed::operator/(const Fixed &rhs) {
    Fixed result(this->toFloat() / rhs.toFloat());
    return result;
}

// pre increment
Fixed&   Fixed::operator++(void) {
    ++this->_bits;
    return *this;
}
// pre decrement
Fixed&   Fixed::operator--(void) {
    --this->_bits;
    return *this;
}

// post increment
Fixed   Fixed::operator++(int) {
    Fixed temp(*this);
    this->_bits++;
    return temp;
}
// post decrement
Fixed   Fixed::operator--(int) {
    Fixed temp(*this);
    this->_bits--;
    return temp;
}


Fixed& Fixed::min(Fixed &value1, Fixed &value2) {
    if (value1.toFloat() < value2.toFloat()) {
        return value1;
    }
    return value2;
}
Fixed& Fixed::max(Fixed &value1, Fixed &value2) {
    if (value1.toFloat() > value2.toFloat()) {
        return value1;
    }
    return value2;
}
const Fixed& Fixed::min(const Fixed &value1, const Fixed &value2) {
    if (value1.toFloat() < value2.toFloat()) {
        return value1;
    }
    return value2;
}
const Fixed& Fixed::max(const Fixed &value1, const Fixed &value2) {
    if (value1.toFloat() > value2.toFloat()) {
        return value1;
    }
    return value2;
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
