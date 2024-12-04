/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:26:24 by brandebr          #+#    #+#             */
/*   Updated: 2024/12/04 11:01:37 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <unistd.h>

#define RESET   "\033[0m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::list<int>		_lst;
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &cpy);
		PmergeMe &operator=(const PmergeMe &cpy);
		~PmergeMe();
		
		void	processInput(int argc, char **argv);
		void	execute();
		void	sortVector(std::vector<int>& vec);
		void	sortList(std::list<int>& _lst);
		void	displayResults(const char *color, std::vector<int> &vec);
		void	showStack(std::vector<int>& min, std::vector<int>& maj);
};

#endif
