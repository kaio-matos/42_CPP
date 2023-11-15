/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/11/14 21:28:10 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <iostream>
#include <fstream>
#include <string>


void copy_replacing(std::string filename, std::string s1, std::string s2);

int	main(int argc, char *argv[]) {
	if (argc < 4) {
		std::cerr << "Error: Not enough arguments." << std::endl;
		return (1);
	} else if (argc > 4) {
		std::cerr << "Error: Too many arguments." << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	copy_replacing(filename, s1, s2);
	return (0);
}

void copy_replacing(std::string filename, std::string s1, std::string s2) {
	std::ifstream file;
	std::string line;
	std::string updated_file = "";

	file.open(filename.c_str());
	if (file.fail()) {
		std::cerr << "Error: fail to open the file" << std::endl;
		return ;
	}
	while (std::getline(file, line)) {
		size_t found = line.find(s1, 0);

		if (found != std::string::npos) {
			while (found != std::string::npos) {
				std::string first = line.substr(0, found);
				std::string second = line.substr(found + s1.length(), line.length());

				updated_file.append(first);
				updated_file.append(s2);
				updated_file.append(second);
				updated_file.append("\n");
				found = line.find(s1, found + 1);
			}
		} else {
			updated_file.append(line);
			updated_file.append("\n");
		}

	}
	file.close();

	std::ofstream output_file;
	output_file.open(filename.append(".replace").c_str());
	output_file << updated_file;
	output_file.close();
}
