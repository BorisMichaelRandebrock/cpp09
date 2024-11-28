/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:13:45 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/28 16:46:05 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include <unistd.h>

#include "BitcoinExchange.hpp"

/*#define RESET   "\033[0m"
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
*/
int main(int argc,  char **argv) {
	std::cout << CYAN << BOLD << ITAL << B_WHI << "Welcome to the Bitcoin exchange 💸" << RESET << std::endl <<  std::endl;
	sleep(2);
	if (argc != 2) {
		std::cout << B_YLW << BOLD_RED << "PLEASE ENTER: <./btc file>" << std::endl;
		return 1;
	}
	try {
		std::cout << BOLD_RED << "Money makes the World go around.." << std::endl << RESET <<std::endl;
		BitcoinExchange ex;
		ex.execute(argv[1]);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
   
