/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:13:45 by brandebr          #+#    #+#             */
/*   Updated: 2024/12/02 12:04:45 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "BitcoinExchange.hpp"

int main(int argc,  char **argv) {
	std::cout << std::endl << CYAN << BOLD << ITAL << B_WHI << "💸 Welcome to the Bitcoin exchange 💸" << RESET << std::endl <<  std::endl;
	sleep(2);
	if (argc != 2) {
		std::cout << B_YLW << BOLD_RED << "PLEASE ENTER: <./btc file>" << std::endl;
		return 1;
	}
	try {
		std::cout << BOLD_RED << B_YLW << "** Money makes the World go around **" << RESET << std::endl <<std::endl;
		sleep(2);
		BitcoinExchange btc;
		btc.execute(argv[1]);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
   
