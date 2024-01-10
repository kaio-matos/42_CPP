/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:24 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/08 21:16:07 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_H
# define BRAIN_H
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdlib.h>

class Brain {
    public:
        Brain(void);
        Brain(const Brain &value);
        Brain& operator=(const Brain &value);
        ~Brain(void);
        std::string *ideas[100];
};

#endif
