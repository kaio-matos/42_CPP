/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/07 20:58:21 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int array[11] = {0,1,2,3,4,5,6,7,8,9,10};

	iter(array, 11, printElement<int>);
	std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;

    std::string stringArray[] = {"Testing", "Multiple", "Strings"};
    iter(stringArray, 3, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}
