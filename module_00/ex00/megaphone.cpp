/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/10/31 20:44:50 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string toUpper(std::string str) {
    std::string converted;

    for(long unsigned int i = 0; i < str.size(); ++i)
        converted += std::toupper(str[i]);
    return (converted);
}

std::string trim(std::string str, char c) {
    std::string converted;

    for(long unsigned int i = 0; i < str.size(); ++i) {
        if (str[i] != c) {
            converted += std::toupper(str[i]);
        }
    }
    return (converted);
}

int	main(int argc, char *argv[]) {


    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }

    for (int count = 1; count < argc; count++) {
        std::string argument = argv[count];

        std::cout << trim(toUpper(argument), '"') << ' ';
    }

    std::cout << std::endl;

	return (0);
}
