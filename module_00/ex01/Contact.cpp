/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:43:12 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/07 21:46:59 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(std::string firstname, std::string lastname, std::string phonenumber, std::string nickname, std::string secret) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->phonenumber = phonenumber;
    this->nickname = nickname;
    this->secret = secret;
}

Contact::~Contact(void) {}

std::string Contact::truncatedFirstName(size_t width)
{
    return this->truncate(this->firstname, width, ".");
}

std::string Contact::truncatedNickName(size_t width)
{
    return this->truncate(this->nickname, width, ".");
}

std::string Contact::truncatedLastName(size_t width)
{
    return this->truncate(this->lastname, width, ".");
}

std::string Contact::truncate(std::string str, size_t width, std::string append) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + append;
    }

    return str;
}

void Contact::print(void) {
    std::cout << "First name   " << this->firstname << std::endl;
    std::cout << "Last name    " << this->lastname << std::endl;
    std::cout << "Phone Number " << this->phonenumber << std::endl;
    std::cout << "Nick name    " << this->nickname << std::endl;
    std::cout << "Secret       " << this->secret << std::endl;
}
