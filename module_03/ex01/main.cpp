/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/12/15 21:14:24 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
	std::cout << "\nCreating Instances -------------------------------------------" << std::endl;
	ClapTrap Joao("Joao");
	ScavTrap Miles("Miles");
	ScavTrap Lucy("Lucy");
	ScavTrap LucyClone(Lucy);
	std::cout << "Creating Instances done -------------------------------------------\n" <<  std::endl;

	Miles.setDamage(2);
	Lucy.setDamage(1);


	std::cout << "\nActing -------------------------------------------" << std::endl;
	Lucy.guardGate();
	Lucy.guardGate();
	Miles.attack(Lucy.getName());

	std::cout << "\n\nLucyClone attacking:" << std::endl;
	LucyClone.attack(Lucy.getName());
	std::cout << "LucyClone done\n\n" <<  std::endl;

	Joao.attack(Lucy.getName());
	std::cout << "Acting done  -------------------------------------------\n" << std::endl;

	std::cout << "\nDestroying Instances -------------------------------------------" << std::endl;
	return 0;
}
