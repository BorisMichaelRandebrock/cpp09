/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:33:39 by brandebr          #+#    #+#             */
/*   Updated: 2024/12/03 16:54:33 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cpy) {
	*this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy) {
	if (this != &cpy) {
		this->_vec = cpy._vec;
		this->_lst = cpy._lst;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::processInput(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		try{
			std::stringstream ss(argv[i]);
			int num;
			if (!(ss >> num) || num <= 0) 
				throw std::invalid_argument("Only positive integers are allowed.");
			_vec.push_back(num);
			_lst.push_back(num);
		} catch (const std::exception &e) {
			std::cerr << RED << "Error: " << YELLOW
				<< e.what() << RESET << std::endl;
			return ;
		}
	}
}

void  PmergeMe::execute() {
	this->displayResults(YELLOW, _vec);
	clock_t start = clock();
	
	sortVector(_vec);

	clock_t end = clock();
	this->displayResults(GREEN, _vec);
	double time_taken = double(end - start) / CLOCKS_PER_SEC;
	std::cout << YELLOW << "Time to process a range of " << GREEN
		<< _vec.size() << YELLOW << " elements with std::vector: " <<
		std::fixed << std::setprecision(6) << GREEN << time_taken * 100 << " us" << RESET << std::endl;


	sleep(1);
/*	std::cout;
	for (size_t i = 0; i < _vec.size(); ++i) {
    volatile int temp = _vec[i]; // Ensure each element is accessed
}
_vec.clear();
_vec.resize(original_size);
std::this_thread::sleep_for(std::chrono::milliseconds(100));
*/
	clock_t start_lst = clock();

	sortList(_lst);

	clock_t end_lst = clock();
	double time_taken_lst = double(end_lst - start_lst) / CLOCKS_PER_SEC;
	std::cout << YELLOW << "Time to process a range of " << GREEN
		<< _lst.size() << YELLOW << " elements with std::list: " <<
		std::fixed << std::setprecision(6) << GREEN << time_taken_lst * 100 << " us" << RESET << std::endl;
}

void  PmergeMe::sortVector(std::vector<int>& _vec) {
	if (_vec.size() <= 1)
		return ;
	std::vector<int> minor;
	std::vector<int> major;

	for (size_t i = 0; i < _vec.size(); i += 2) {
		if (i + 1 < _vec.size()) {
			if (_vec[i] < _vec[i + 1]) {
				minor.push_back(_vec[i]);
				major.push_back(_vec[i + 1]);
			} else {
				minor.push_back(_vec[i + 1]);
				major.push_back(_vec[i]);
			}
		} else {
			major.push_back(_vec[i]);
		}
	}
	sortVector(major);

	for (size_t i = 0; i < minor.size(); ++i) {
		std::vector<int>::iterator pos = std::lower_bound(major.begin(), major.end(), minor[i]);
		major.insert(pos, minor[i]);
	}
	_vec = major; 
}

void PmergeMe::sortList(std::list<int>& _lst) {
		if (_lst.size() <= 1)
		return ;
	std::list<int> minor;
	std::list<int> major;

	std::list<int>::iterator it = _lst.begin();
	while (it != _lst.end()) {
		int a = *it;
		++it;
		if (it != _lst.end()) {
			int b = *it;
			++it;
			if (a < b) {
				minor.push_back(a);
				major.push_back(b);
			} else {
				minor.push_back(b);
				major.push_back(a);
			}
		} else {
			major.push_back(a);
		}
	}
	sortList(major);

	for (std::list<int>::iterator it = minor.begin(); it != minor.end(); ++it) {
		std::list<int>::iterator pos = major.begin();
		while (pos != major.end() && *pos <= *it)
			++pos;
		major.insert(pos,*it);
	}
	_lst = major;
}

void PmergeMe::displayResults(const char *color, std::vector<int> &vec) {
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) { 
		std::cout << color << *it << " " << RESET;
	}
	std::cout << std::endl;
}
