/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/10 18:39:55 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void PDFMain()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}


void TestMultipleAnimals() {
	Animal *animals[10];

	for (int i = 0; i < 10; i++) {
		if (i < 5) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	for (int i = 0; i < 10; i++) {
		animals[i]->makeSound();
		delete animals[i];
	}
}

void TestDeepCopy() {
	Dog *dog = new Dog();
	Dog *copyDog = new Dog(*dog);

	std::cout << "Dog: " << *dog->getBrain().ideas[0] << " Copy: " << *copyDog->getBrain().ideas[0] << std::endl;
	std::cout << "Dog: " << *dog->getBrain().ideas[99] << " Copy: " << *copyDog->getBrain().ideas[99] << std::endl;

	delete dog;
	delete copyDog;

	Cat *cat = new Cat();
	Cat *copyCat = new Cat(*cat);

	std::cout << "Cat: " << *cat->getBrain().ideas[0] << " Copy: " << *copyCat->getBrain().ideas[0] << std::endl;
	std::cout << "Cat: " << *cat->getBrain().ideas[99] << " Copy: " << *copyCat->getBrain().ideas[99] << std::endl;

	delete cat;
	delete copyCat;
}


int main()
{
	std::cout << "----------------------------" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "----------------------------" << std::endl;

	PDFMain();

	std::cout << "----------------------------" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "----------------------------" << std::endl;

	TestMultipleAnimals();

	std::cout << "----------------------------" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "----------------------------" << std::endl;

	TestDeepCopy();

	std::cout << "----------------------------" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Animal not_allowed = new Animal();
	return 0;
}
