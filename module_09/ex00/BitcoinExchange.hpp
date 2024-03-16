/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/03/13 20:57:02 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_CPP
#define BITCOIN_EXCHANGE_CPP

#include <iostream>
#include <ctime>
#include <map>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include <dirent.h>

#define TM_YEAR_BASE 1900

class BitcoinExchange {

public:
	BitcoinExchange(std::map<std::string, double> database);
	BitcoinExchange(const BitcoinExchange &value);
	BitcoinExchange &operator=(const BitcoinExchange &value);
	~BitcoinExchange(void);

	void convert(std::string date, double amount) const;
	bool isValidAmount(double amount) const;
	bool isValidDate(std::string date) const;

private:
	std::map<std::string, double> _database;
};

#endif
