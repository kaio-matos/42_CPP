/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/12/05 21:08:28 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

void logClapTraps(void);

void	TestLogs() {
	// Death test
	std::cout << "DEATH TEST" << std::endl;
	ClapTrap Miles("Miles");
	ClapTrap Lucy("Lucy");
	Miles.setDamage(10);
	Lucy.setDamage(1);

	Miles.attack(Lucy.getName()); // hit kill
	Lucy.attack(Miles.getName());

	Miles.log();
	Lucy.log();

	// Repair test
	std::cout << "REPAIR TEST" << std::endl;
	ClapTrap Silas("Silas");
	ClapTrap Oscar("Oscar");
	Silas.setDamage(2);
	Silas.attack(Oscar.getName());
	Silas.attack(Oscar.getName());
	Oscar.beRepaired(4);

	Oscar.log();
	Silas.log();

	// Energy test
	std::cout << "ENERGY TEST" << std::endl;
	ClapTrap James("James");
	ClapTrap Graham("Graham");
	Graham.setDamage(1);
	Graham.attack(James.getName());
	Graham.attack(James.getName());
	Graham.attack(James.getName());
	Graham.attack(James.getName());
	Graham.attack(James.getName());
	Graham.attack(James.getName());
	Graham.attack(James.getName());
	Graham.attack(James.getName());
	Graham.attack(James.getName());
	Graham.attack(James.getName());
	Graham.attack(James.getName());
	Graham.beRepaired(1);

	James.log();
	Graham.log();
}


void	TestFight() {
	ClapTrap John("John");
	ClapTrap Mark("Mark");
	John.setDamage(2);
	Mark.setDamage(1);

	std::cout << "-------- John X Mark --------" << std::endl;
	John.attack(Mark.getName());
	Mark.attack(John.getName());
	John.attack(Mark.getName());
	Mark.attack(John.getName());
	John.attack(Mark.getName());
	Mark.attack(John.getName());
	John.attack(Mark.getName());
	Mark.attack(John.getName());
	John.attack(Mark.getName());
	Mark.attack(John.getName());
	Mark.attack(John.getName());

	John.log();
	Mark.log();
	std::cout << "---------------------- John Wins! ----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	ClapTrap Oliver("Oliver");
	ClapTrap Amelia("Amelia");
	Oliver.setDamage(2);
	Amelia.setDamage(1);
	std::cout << "-------- Oliver X Amelia --------" << std::endl << std::endl;
	Amelia.attack(Oliver.getName());
	Amelia.attack(Oliver.getName());
	Amelia.attack(Oliver.getName());
	Amelia.attack(Oliver.getName());
	Amelia.attack(Oliver.getName());
	Amelia.attack(Oliver.getName());
	Amelia.attack(Oliver.getName());
	Amelia.attack(Oliver.getName());
	Amelia.attack(Oliver.getName());
	Amelia.attack(Oliver.getName());
	Amelia.attack(Oliver.getName());

	Oliver.log();
	Amelia.log();
	std::cout << "---------------------- Amelia Wins! ----------------------" << std::endl;

}

ClapTrap &TestDestructionCreateClaptraps() {
	ClapTrap Scarlet("Scarlet");
	ClapTrap *Marley = new ClapTrap("Marley");
	logClapTraps();
	return (*Marley);
}

void TestDestruction() {
	ClapTrap &marley = TestDestructionCreateClaptraps();
	logClapTraps();
	delete &marley;
}

int main( void ) {
	std::cout << "------------------------------------------------ TestDestruction ------------------------------------------------" << std::endl;
	TestDestruction();
	std::cout << "------------------------------------------------ /TestDestruction ------------------------------------------------" << std::endl;

	// std::cout << "------------------------------------------------ TestLogs ------------------------------------------------" << std::endl;
	// TestLogs();
	// std::cout << "------------------------------------------------ /TestLogs ------------------------------------------------" << std::endl;

	// std::cout << "------------------------------------------------ TestFight ------------------------------------------------" << std::endl;
	// TestFight();
	// std::cout << "------------------------------------------------ /TestFight ------------------------------------------------" << std::endl;
	return 0;
}

void logClapTraps() {
	std::cout << "Instatiated Claptraps: " <<  ClapTrap::clap_traps_length << std::endl;
    for (int i = 0; i < ClapTrap::clap_traps_length; i++) {
		std::cout << "[" << i << "] " <<  ClapTrap::clap_traps[i]->getName() << std::endl;
    }
}
