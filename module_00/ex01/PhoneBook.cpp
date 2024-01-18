/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:43:12 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/17 20:28:59 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->_size = 0;
    this->_last_included_index = -1;
}

PhoneBook::~PhoneBook(void) {
}

void PhoneBook::add(Contact contact) {

    if (this->_last_included_index == -1)
        this->_last_included_index = 0;

    if (this->_last_included_index < 8) {
        this->_contacts[this->_last_included_index] = contact;
        this->_last_included_index++;
        if (this->_size < 8)
            this->_size++;
    } else {
        this->_last_included_index = 0;
        this->_contacts[this->_last_included_index] = contact;
        this->_last_included_index++;
    }
}

Contact *PhoneBook::search(unsigned int index) {
    for (unsigned int i = 0; i < this->_size; i++) {
        if (i == index) {
            return &this->_contacts[i];
        }
    }
    return NULL;
}

void PhoneBook::print(void) {
    for (unsigned int i = 0; i < this->_size; i++) {
        Contact contact = this->_contacts[i];

        std::cout << std::setw(10) << i + 1  << "|" << std::setw(10) << contact.truncatedFirstName() << "|" << std::setw(10) << contact.truncatedLastName() << "|" << std::setw(10) << contact.truncatedNickName() << "|" << std::endl;
    }
}
