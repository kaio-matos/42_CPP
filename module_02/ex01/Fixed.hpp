/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/22 22:02:32 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
# define FIXED_H

#include <iomanip>
#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed(void);
        Fixed(const Fixed &value);
        Fixed(const int value);
        Fixed(const float value);
        Fixed& operator=(const Fixed &value);
        ~Fixed(void);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;



    private:
        int                 _bits;
        static const int    _fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& dt);

#endif
