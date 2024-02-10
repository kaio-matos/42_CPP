/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/09 21:35:24 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include <dirent.h>

int main(int argc, char **argv)
{
  (void)argv;
  if (argc != 2) {
    std::cerr << "Bad arguments" << std::endl;
    exit(1);
  }

  RPN expression(argv[1]);

	return 0;
}
