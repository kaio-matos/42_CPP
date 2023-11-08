/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:43:12 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/07 21:54:20 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->size = 0;
    this->last_included_index = -1;
}

PhoneBook::~PhoneBook(void) {
}

void PhoneBook::add(Contact contact) {

    if (this->last_included_index == -1)
        this->last_included_index = 0;

    if (this->last_included_index < 8) {
        this->contacts[this->last_included_index] = contact;
        this->last_included_index++;
        if (this->size < 8)
            this->size++;
    } else {
        this->last_included_index = 0;
        this->contacts[this->last_included_index] = contact;
        this->last_included_index++;
    }
}

Contact *PhoneBook::search(unsigned int index) {
    for (unsigned int i = 0; i < this->size; i++) {
        if (i == index) {
            return &this->contacts[i];
        }
    }
    return NULL;
}

void PhoneBook::print(void) {
    for (unsigned int i = 0; i < this->size; i++) {
        Contact contact = this->contacts[i];

        std::cout << std::setw(10) << i + 1  << "|" << std::setw(10) << contact.truncatedFirstName() << "|" << std::setw(10) << contact.truncatedLastName() << "|" << std::setw(10) << contact.truncatedNickName() << "|" << std::endl;
    }
}
