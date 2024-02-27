/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/22 20:43:51 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iomanip>
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
    Serializer(void);
    Serializer(const Serializer &value);
    Serializer &operator=(const Serializer &value);
    ~Serializer(void);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif
