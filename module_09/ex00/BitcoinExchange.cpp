/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/08 21:06:32 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <ctime>

BitcoinExchange::BitcoinExchange(std::map<std::string, double> database): _database(database) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &value): _database(value._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &value) {
	if (this != &value)
		_database = value._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}


void BitcoinExchange::convert(std::string date, double amount) const {
	if (!BitcoinExchange::isValidAmount(amount) || !BitcoinExchange::isValidDate(date)){
		return ;
	}

	std::map<std::string, double>::const_iterator found = this->_database.lower_bound(date);

	if (found->first != date && found != _database.begin()) {
		found--;
	}
	std::string found_date = found->first;
	double found_price = found->second;

	if (!found_date.empty()) {
		double converted = amount * found_price;
		std::cout << date << " => " << amount << " = " << converted << std::endl;
	} else {
		std::cout << date << " => " << amount << std::endl;
	}
}

bool BitcoinExchange::isValidAmount(double amount) {
	if (amount < 0) {
		std::cout << "Error: not a positive number" << std::endl;
		return false;
	}

	if (amount > 1000) {
		std::cout << "Error: too large number" << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isValidDate(std::string date) {
	std::tm tm = {};
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	return true;
}
