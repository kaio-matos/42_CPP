/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/13 20:38:18 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double> readDatabasePrices(std::string filename, char separator);
bool readFileAndConvert(BitcoinExchange exchange, std::string filename, char separator);

int main(int argc, char **argv)
{
  if (argc != 2) {
    std::cerr << "Bad arguments" << std::endl;
    exit(1);
  }

  std::map<std::string, double> database(readDatabasePrices("data.csv", ','));

  if (database.empty()) {
    return 1;
  }

  BitcoinExchange Exchange(database);

  if (!readFileAndConvert(Exchange, argv[1], '|')) {
    return 1;
  };

	return 0;
}

void trimstr(std::string &str) {
	static const char      whitespace[] = " \t\n\r\f\v";
	std::string::size_type start = str.find_first_not_of(whitespace);
	if (start == std::string::npos)
		str.erase();
	std::string::size_type end = str.find_last_not_of(whitespace);
	str.erase(end + 1).erase(0, start);
}

bool isFloat(std::string string) {
    trimstr(string);
    std::istringstream iss(string);
    float f;
    iss >> f;
    return iss.eof() && !iss.fail();
}

bool validateFileOpening(std::ifstream &file, std::string filename) {
  if (file.fail()) {
    std::cerr << "Error opening the file: " << filename << std::endl;
    file.close();
    return false;
  }

  DIR *dir = opendir(filename.c_str());

  if (dir != NULL) {
    std::cerr << "Error opening the file: " << filename << std::endl;
    closedir(dir);
    return false;
  }
  return true;
}

std::map<std::string, double> readDatabasePrices(std::string filename, char separator) {
  std::ifstream file(filename.c_str());
  std::map<std::string, double> result;
  std::string line, date, price;

   if (!validateFileOpening(file, filename)) {
    return result;
  }

  std::getline(file, line); // ignore first line

  while (std::getline(file, line)) {
    if (line.empty()) continue;
    std::stringstream ss(line);
    std::getline(ss, date, separator);
    trimstr(date);

    if (ss.fail() || date.empty()) continue;

    std::getline(ss, price);

    if (ss.fail()) continue;

    result[date] = std::atof(price.c_str());
  }

  file.close();

  return result;
}

bool readFileAndConvert(BitcoinExchange exchange, std::string filename, char separator) {
  std::ifstream file(filename.c_str());
  std::string line, date, amount;

  if (!validateFileOpening(file, filename)) {
    return false;
  }

  std::getline(file, line); // ignore first line

  if (line != "date | value") {
    std::cout << "Error: invalid header => " << line << std::endl;
  }

  while (std::getline(file, line)) {
    if (line.empty()) continue;
    std::stringstream ss(line);
    std::getline(ss, date, separator);
    trimstr(date);

    if (ss.fail() || date.empty()) {
  		std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::getline(ss, amount);
    trimstr(amount);

    if (ss.fail() || !isFloat(amount)) {
  		std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }

    exchange.convert(date, std::atof(amount.c_str()));
  }

  file.close();
  return true;
}
