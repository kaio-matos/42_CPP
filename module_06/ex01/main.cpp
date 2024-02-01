/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/31 21:56:19 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


void printData(std::string name, Data data) {
	std::cout << name << " {\n"
              << "  Name: "<< data.name << "\n"
	          << "  Email: "<< data.email << "\n"
	          << "  Age: "<< data.age << "\n"
	          << "} " << std::endl;
}

int main(void)
{
	Data User = {
		.name = "John",
		.email = "john@example.com",
		.age = 27
	};

	printData("Original Data:", User);
    std::cout << std::endl;

	uintptr_t serializedUser = Serializer::serialize(&User);

	std::cout << "Serialized Data: " << serializedUser << std::endl;

	Data *deserializedUser = Serializer::deserialize(serializedUser);

    std::cout << std::endl;

	printData("Deserialized Data:", *deserializedUser);

	std::cout << "Original Pointer:     " << &User << std::endl;
	std::cout << "Deserialized Pointer: " << deserializedUser << std::endl;

	return 0;
}
