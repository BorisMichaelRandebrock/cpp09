/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:22:03 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/28 19:30:34 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <exception>
# include <iomanip>
# include <string>

#define RESET   "\033[0m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BOLD "\x1B[1m"
#define ITAL "\x1B[3m"
#define UNDL "\x1B[4m"

#define B_RED "\x1B[41m"
#define B_GRN "\x1B[42m"
#define B_YLW "\x1B[43m"
#define B_BLU "\x1B[44m"
#define B_MAG "\x1B[45m"
#define B_CYN "\x1B[46m"
#define B_WHI "\x1B[47m"


class BitcoinExchange {
	private:
		std::map<std::string, double> _quotes;
		void readDatabase();
		bool validateDate(const std::string &date);
		double validatePrice(const std::string &sValue);
		void applyExchangeRate(const std::string &date, double price);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange &operator=(const BitcoinExchange &);
		~BitcoinExchange();

		void execute(char const *file);

		class FileClosedException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "\033[31mCould not open file!\033[0m";
				}
		};

		class WrongFormatException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "\033[31mFile format incorrect!\033[0m";
				}
		};

		class InvalidPriceFormatException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "\033[31mPrice format incorrect!\033[0m";
				}
		};
};

#endif
