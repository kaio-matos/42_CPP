/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/18 20:45:20 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <iostream>

int	main(void) {
	std::string message     = "HI THIS IS BRAIN";
	std::string *stringPTR  = &message;
	std::string &stringREF  = message;

	std::cout << "ADDRESSES" << std::endl;
	std::cout << "message    " << &message << std::endl;
	std::cout << "stringPTR  " << stringPTR << std::endl;
	std::cout << "stringREF  " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "VALUE" << std::endl;
	std::cout << "message    " << message << std::endl;
	std::cout << "stringPTR  " << *stringPTR << std::endl;
	std::cout << "stringREF  " << stringREF << std::endl;

	return (0);
}
