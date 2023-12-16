/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/12/15 21:30:52 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void ) {
	std::cout << "\nCreating Instances -------------------------------------------" << std::endl;
	FragTrap Joao("Joao");
	FragTrap Miles("Miles");
	FragTrap Fabricio("Fabricio");
	std::cout << "Creating Instances done -------------------------------------------\n" <<  std::endl;

	std::cout << "\nActing -------------------------------------------" << std::endl;
	Joao.highFivesGuys();
	Miles.highFivesGuys();
	Fabricio.highFivesGuys();

	FragTrap *Marcos = new FragTrap("Marcos");
	Marcos->highFivesGuys();
	std::cout << "Acting done  -------------------------------------------\n" << std::endl;

	delete Marcos;

	std::cout << "\nDestroying Instances -------------------------------------------" << std::endl;
	return 0;
}
