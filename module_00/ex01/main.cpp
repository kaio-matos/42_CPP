/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/07 22:03:32 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

std::string askField(std::string fieldname);
void askCommand(PhoneBook phonebook);

enum Commands {
	COMMAND_SEARCH,
	COMMAND_ADD,
	COMMAND_EXIT,
	COMMAND_INVALID
};

void SEARCH(PhoneBook phonebook) {
	std::string id;
    int         id_int;

    phonebook.print();

    std::cout << "Enter phone ID: ";
    std::cin >> id;
    std::cout << std::endl;

    id_int = std::atoi(id.c_str()) - 1;
    if (id_int < 0) {
         std::cout << "ID: " << id << " not found" << std::endl;
         return ;
    }
	Contact *found = phonebook.search(id_int);

	if (found) {
    	std::cout << "ID: "<< id << std::endl;
		found->print();
	} else {
	    std::cout << "ID: " << id << " not found" << std::endl;
	}
}

void ADD(PhoneBook *phonebook) {
	std::string firstname = askField("First Name");
	std::string lastname = askField("Last Name");
	std::string phonenumber = askField("Phone Number");
	std::string nickname = askField("Nickname");
	std::string secret = askField("A big secret");
	std::cout << std::endl;

	phonebook->add(Contact(
		firstname,
		lastname,
		phonenumber,
		nickname,
		secret
	));
    std::cout << std::endl;
}

void EXIT() {
	exit(0);
}

int	main(void) {
	PhoneBook phonebook;

	// phonebook.add(Contact("Marcos", "Sobrenome", "Fulano 2", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Lucas", "Sobrenome", "Fulano 3", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Kaio", "Sobrenome", "Fulano 4", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Matos", "Sobrenome", "Fulano 5", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Agatha", "Sobrenome", "Fulano 6", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Joana", "Sobrenome", "Fulano 7", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Maria", "Sobrenome", "Fulano 8", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Bartholomew", "Sobrenome", "CiclanoBeutrano", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Cristopher", "Sobrenome", "Fulano 9", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Guilherme", "Sobrenome", "Fulano 9", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Felipe", "Sobrenome", "Fulano 10", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Luana", "Sobrenome", "Fulano 11", "+55 11 99999-9999", "secret"));
	// phonebook.add(Contact("Tiago", "Sobrenome", "Fulano 12", "+55 11 99999-9999", "secret"));

	askCommand(phonebook);
	return (0);
}

std::string askField(std::string fieldname) {
	std::string result = "";

    std::cout << "Enter contact " << fieldname << ": ";
    std::cin >> result;
	if (result.empty())
		return askField(fieldname);
	return result;
}

void askCommand(PhoneBook phonebook) {
	std::string command_str;
	Commands command = COMMAND_INVALID;

	std::cout << std::endl;
    std::cout << "Enter a command: ";
	std::cin >> command_str;

	if (command_str.compare("ADD") == 0)
		command = COMMAND_ADD;
	else if (command_str.compare("SEARCH") == 0)
		command = COMMAND_SEARCH;
	else if (command_str.compare("EXIT") == 0)
		command = COMMAND_EXIT;
	else command = COMMAND_INVALID;

	switch (command)
	{
		case COMMAND_ADD:
			ADD(&phonebook);
			askCommand(phonebook);
			break;
		case COMMAND_SEARCH:
			SEARCH(phonebook);
			askCommand(phonebook);
			break;
		case COMMAND_EXIT:
			EXIT();
			break;
		default:
			std::cout << "ERROR: Invalid command" << std::endl;
			askCommand(phonebook);
			break;
	}
}
