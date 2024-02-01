/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/31 22:38:34 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base BaseInstance;
	A AInstance;
	B BInstance;
	C CInstance;


	std::cout << "A Instance:" << std::endl;
	BaseInstance.identify(&AInstance);
	BaseInstance.identify(AInstance);
	std::cout << std::endl;

	std::cout << "B Instance:" << std::endl;
	BaseInstance.identify(&BInstance);
	BaseInstance.identify(BInstance);
	std::cout << std::endl;

	std::cout << "C Instance:" << std::endl;
	BaseInstance.identify(&CInstance);
	BaseInstance.identify(CInstance);
	std::cout << std::endl;
	std::cout << std::endl;


	Base *randomInstance = BaseInstance.generate();

	std::cout << "Random Instance:" << std::endl;
	BaseInstance.identify(randomInstance);
	BaseInstance.identify(*randomInstance);
	std::cout << std::endl;

	delete randomInstance;
	return 0;
}
