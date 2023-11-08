/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:41:31 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/07 21:47:06 by kmatos-s         ###   ########.fr       */
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
        Contact      contacts[8];
        unsigned int size;
        int          last_included_index;
};

#endif
