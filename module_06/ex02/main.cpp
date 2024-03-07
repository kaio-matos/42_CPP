/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/06 21:22:04 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	A AInstance;
	B BInstance;
	C CInstance;


	std::cout << "A Instance:" << std::endl;
	identify(&AInstance);
	identify(AInstance);
	std::cout << std::endl;

	std::cout << "B Instance:" << std::endl;
	identify(&BInstance);
	identify(BInstance);
	std::cout << std::endl;

	std::cout << "C Instance:" << std::endl;
	identify(&CInstance);
	identify(CInstance);
	std::cout << std::endl;
	std::cout << std::endl;


	Base *randomInstance = generate();

	std::cout << "Random Instance:" << std::endl;
	identify(randomInstance);
	identify(*randomInstance);
	std::cout << std::endl;

	delete randomInstance;
	return 0;
}
