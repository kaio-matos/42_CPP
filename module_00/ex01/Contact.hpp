/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:41:31 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/07 21:27:23 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>
#include <cstdlib>

class Contact {
    public:
        Contact(void);
        Contact(std::string firstname, std::string lastname, std::string phonenumber, std::string nickname, std::string secret);
        ~Contact(void);
        std::string firstname;
        std::string lastname;
        std::string phonenumber;
        std::string nickname;
        std::string secret;
        std::string truncatedFirstName(size_t width = 10);
        std::string truncatedLastName(size_t width = 10);
        std::string truncatedNickName(size_t width = 10);
        void print(void);

    private:
        std::string truncate(std::string str, size_t width, std::string append);
};

#endif
