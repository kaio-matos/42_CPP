/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/10 18:36:36 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_H
# define ANIMAL_H
#include <iostream>

class Animal {
    public:
        Animal(void);
        Animal(const Animal &value);
        Animal& operator=(const Animal &value);
        virtual ~Animal(void);
        virtual void makeSound(void) const = 0;
        std::string getType() const;

    protected:
        std::string type;
};

#endif
