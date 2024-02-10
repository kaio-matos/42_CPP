/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:57:11 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/08 20:43:05 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_CPP
#define BITCOIN_EXCHANGE_CPP

#include <iostream>
#include <map>

class BitcoinExchange {

public:
	BitcoinExchange(std::map<std::string, double> database  );
	BitcoinExchange(const BitcoinExchange &value);
	BitcoinExchange &operator=(const BitcoinExchange &value);
	~BitcoinExchange(void);

	void convert(std::string date, double amount) const;
	static bool isValidAmount(double amount);
	static bool isValidDate(std::string date);

private:
	std::map<std::string, double> _database;
};

#endif
