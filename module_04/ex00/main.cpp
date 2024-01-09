/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/08 21:07:18 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void PDFMain() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}
void PDFWrongMain() {
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	delete meta;
	delete i;
}

int main()
{
	PDFMain();
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	PDFWrongMain();
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	const Cat* cat = new Cat();
	const Dog* dog = new Dog();

	delete cat;
	delete dog;
	return 0;
}
