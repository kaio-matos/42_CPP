/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/13 21:28:20 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::map<std::string, double> database): _database(database) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &value): _database(value._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &value) {
	if (this != &value)
		_database = value._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}


void BitcoinExchange::convert(std::string date, double amount) const {
	if (!isValidAmount(amount) || !isValidDate(date)){
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

bool BitcoinExchange::isValidAmount(double amount) const {
	if (amount < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}

	if (amount > 1000) {
		std::cout << "Error: too large number." << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isValidDate(std::string date) const {
	std::tm Date = {};

	if (!strptime(date.c_str(), "%Y-%m-%d", &Date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	std::tm firstDate = {};
	std::map<std::string, double>::const_iterator first = this->_database.begin();

	strptime(first->first.c_str(),"%Y-%m-%d", &firstDate);

	bool isBeforeYear = (Date.tm_year + TM_YEAR_BASE) < (firstDate.tm_year + TM_YEAR_BASE);
	bool isSameYear = (Date.tm_year + TM_YEAR_BASE) == (firstDate.tm_year + TM_YEAR_BASE);
	bool isBeforeMonth = Date.tm_mon < firstDate.tm_mon;
	bool isSameMonth = Date.tm_mon == firstDate.tm_mon;
	bool isBeforeDay = Date.tm_mday < firstDate.tm_mday;

	if (isBeforeYear) {
		std::cout << "Error: bad input => " << date << " is before than first entry " << first->first << std::endl;
		return false;
	}
	if (isSameYear && isBeforeMonth) {
		std::cout << "Error: bad input => " << date << " is before than first entry " << first->first << std::endl;
		return false;
	}
	if (isSameMonth && isBeforeDay) {
		std::cout << "Error: bad input => " << date << " is before than first entry " << first->first << std::endl;
		return false;
	}

	return true;
}
