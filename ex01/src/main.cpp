/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:32:44 by brandebr          #+#    #+#             */
/*   Updated: 2024/12/02 18:56:13 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Usage: ./RPN \"expression\"" << RESET << std::endl;
            return 1;
	}
	try {
		RPN calculator;
		double result = calculator.evaluateRPN(argv[1]);
		std::cout << YELLOW << "Result: " << GREEN << result << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
