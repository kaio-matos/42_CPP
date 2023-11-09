/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/09 20:20:57 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

void createHordeAnnoucing(std::string first_hordename, std::string second_hordename, int amount) {
	Zombie *zombies = zombieHorde(amount, first_hordename);

	for (int i = 0; i < amount; i++) {
		zombies[i].announce();
	}

	delete [] zombies;

	std::cout << std::endl;
	std::cout << std::endl;

	zombies = zombieHorde(amount, second_hordename);

	for (int i = 0; i < amount; i++) {
		std::ostringstream name;
		name << second_hordename << " " << i;
		zombies[i].setName(name.str());
		zombies[i].announce();
	}

	delete [] zombies;
}

int	main(void) {

	createHordeAnnoucing("João", "Fabrício", 5);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	createHordeAnnoucing("Maria", "Lucas", 5);
	return (0);
}
