/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:11:54 by brandebr          #+#    #+#             */
/*   Updated: 2024/12/03 14:55:02 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 3) {
		std::cerr << RED << "At least two numbers are required" << RESET << std::endl;
		return 1;
	}
	PmergeMe sorter;
	sorter.processInput(argc, argv);
	sorter.execute();

	return 0;
}
