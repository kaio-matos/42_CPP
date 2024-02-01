/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:39:41 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/31 21:49:56 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#include <iomanip>
#include <iostream>

typedef struct Data {
    std::string  name;
    std::string  email;
    unsigned int age;
} Data;

#endif
