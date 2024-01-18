/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:41:31 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/17 20:29:31 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include <iomanip>

#include "Contact.hpp"


class PhoneBook {

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void add(Contact contact);
        Contact *search(unsigned int index);
        void print(void);

    private:
        Contact      _contacts[8];
        unsigned int _size;
        int          _last_included_index;
};

#endif
