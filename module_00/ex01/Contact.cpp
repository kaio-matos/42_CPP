/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:43:12 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/17 20:28:05 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(std::string firstname, std::string lastname, std::string phonenumber, std::string nickname, std::string secret) {
    this->_firstname = firstname;
    this->_lastname = lastname;
    this->_phonenumber = phonenumber;
    this->_nickname = nickname;
    this->_secret = secret;
}

Contact::~Contact(void) {}

std::string Contact::truncatedFirstName(size_t width)
{
    return this->truncate(this->_firstname, width, ".");
}

std::string Contact::truncatedNickName(size_t width)
{
    return this->truncate(this->_nickname, width, ".");
}

std::string Contact::truncatedLastName(size_t width)
{
    return this->truncate(this->_lastname, width, ".");
}

std::string Contact::truncate(std::string str, size_t width, std::string append) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + append;
    }

    return str;
}

void Contact::print(void) {
    std::cout << "First name   " << this->_firstname << std::endl;
    std::cout << "Last name    " << this->_lastname << std::endl;
    std::cout << "Phone Number " << this->_phonenumber << std::endl;
    std::cout << "Nick name    " << this->_nickname << std::endl;
    std::cout << "Secret       " << this->_secret << std::endl;
}
