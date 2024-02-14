/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/08 21:15:40 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::srand(time(0));
    std::ostringstream oss;
    for (int i = 0; i < 100; i++) {
        oss << "idea " << i << " " << std::rand() % 1000;
        this->ideas[i] = new std::string(oss.str());
        oss.str("");
    }
    std::cout << "Contructed Brain" << std::endl;
}

Brain::Brain(const Brain &value) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = new std::string(*value.ideas[i]);
    }
}

Brain& Brain::operator=(const Brain &value) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = value.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    for (int i = 0; i < 100; i++) {
        delete this->ideas[i];
    }
    std::cout << "Destroyed Brain" << std::endl;
}
