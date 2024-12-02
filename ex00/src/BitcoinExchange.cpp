/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:21:43 by brandebr          #+#    #+#             */
/*   Updated: 2024/12/02 11:50:30 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	readDatabase();
}
/*
   BitcoinExchange::BitcoinExchange(const std::string &filename) {
   readDatabase(filename);
   }*/

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
	if (this != &cpy)
		*this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy) {
	if (this != &cpy)
		this->_quotes = cpy._quotes;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readDatabase() {
	/*std::ifstream file("data.csv");

	  file.close();*/
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw FileClosedException();
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string date, price;
		std::istringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, price, ',');
		double priceValue = 0.0;
		std::istringstream priceStream(price);

		if (!(priceStream >> priceValue))
			throw InvalidPriceFormatException();
		_quotes[date] = priceValue;
	}
	file.close();
}

bool BitcoinExchange::validateDate(const std::string &date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	std::istringstream yearStream(date.substr(0, 4));
	int year;
	yearStream >> year;
	std::istringstream monthStream(date.substr(5, 2));
	int month;
	monthStream >> month;
	std::istringstream dayStream(date.substr(8, 2));
	int day;
	dayStream >> day;
	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day < 1 || day > 31)
				return false;
			break;
		case 4: case 6: case 9: case 11:
			if (day < 1 || day > 30)
				return false;
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				if (day < 1 || day > 29)
					return false;
			} else {
				if (day < 1 || day > 28)
					return false;
			}
			break;
		default:
			return false;
	}
	return true;
}

double BitcoinExchange::validatePrice(const std::string &sValue) {
	std::string trimmedValue = sValue;
	trimmedValue.erase(trimmedValue.find_last_not_of(" \t\n\r") + 1);
	trimmedValue.erase(0, trimmedValue.find_first_not_of(" \t\n\r")); 
	double priceValue;
	std::istringstream priceStream(trimmedValue);

	if (!(priceStream >> priceValue)) {
		std::cout << RED << "Error: bad value input => " << trimmedValue << RESET << std::endl;
		return -1;
	}
	if (priceValue < 0) {
		std::cout << RED << "Error: not a positive number => " << trimmedValue << RESET << std::endl;
		return -1;
	}
	if (priceValue > 1000) {
		std::cout << RED << "Error: too large a number => " << trimmedValue << RESET << std::endl;
		return -1;
	}
	return priceValue;
}

void BitcoinExchange::applyExchangeRate(const std::string &date, double price) {
	std::map<std::string, double>::iterator it = _quotes.find(date);
	if (it != _quotes.end()) {
		std::cout << GREEN << date << " => " << price << " = " << std::fixed << std::setprecision(2)
			<< it->second *price << RESET << std::endl;
	} else {
		std::map<std::string, double>::iterator it2 = _quotes.lower_bound(date);
		if (it2 == _quotes.begin()) {
			std::cout << GREEN << date << " => " << price << " = " << std::fixed << std::setprecision(2)
				<< it2->second * price  << RESET << std::endl;
		}
		--it2;
		std::cout << GREEN << date << " => " << price << " = " << std::fixed << std::setprecision(2)
			<< it2->second *price << RESET << std::endl;
	}
}

void BitcoinExchange::execute(char const *fileName) {
	std::ifstream file(fileName);
	if (!file.is_open())
		throw FileClosedException();

	std::string line;
	std::getline(file, line);

	if (line != "date | value")
		throw WrongFormatException();

	while (std::getline(file, line)) {
		std::string date;
		std::string sValue;
		double priceValue;
		std::istringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, sValue, '|');

		if (!date.empty()) {
			date.erase(date.find_last_not_of(" \t\n\r") + 1);
			date.erase(0, date.find_first_not_of(" \t\n\r"));

			sValue.erase(sValue.find_last_not_of(" \t\n\r") + 1);
			sValue.erase(0, sValue.find_first_not_of(" \t\n\r"));
		}
		if (!validateDate(date)) {
			std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
			continue ;
		}
		if (!sValue.empty()) {
			sValue.erase(sValue.find_last_not_of(" \t\n\r") + 1);
			sValue.erase(0, sValue.find_first_not_of(" \t\n\r"));
			priceValue = validatePrice(sValue);

			if (priceValue != -1)
				applyExchangeRate(date, priceValue);
		}



		/*		priceValue = validatePrice(sValue);
				if (priceValue != -1) {
				applyExchangeRate(date, priceValue);
				}


*/


	}

	file.close();
}


