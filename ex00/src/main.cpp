/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:05 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/27 14:19:43 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <unistd.h>
#include <list>

#include "MutantStack.hpp"

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main() {
	std::cout << CYAN << BOLD << "Welcome to the Mutant Stack Experiment!" << RESET << std::endl <<  std::endl;
	sleep(2);

	MutantStack<int> mstack;

	std::cout << YELLOW << "Intern is adding numbers to the Mutant Stack... " << RESET << std::endl;
	sleep(1);
	mstack.push(42);
	sleep(1);
	mstack.push(17);
	sleep(1);
	mstack.push(99);
	sleep(1);
	mstack.push(77);

	std::cout << GREEN << "The stack has been mutated! Let's see what we have here:" << RESET << std::endl;
	sleep(1);

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << BOLD_RED << "Value: " << *it << RESET << std::endl;
		sleep(1);
	}

	std::cout << BLUE << "The intern wonders: What could possibly go wrong with this stack?" << RESET << std::endl;
	sleep(2);

	std::cout << MAGENTA << "Intern decides to push some more values..." << RESET << std::endl;
	sleep(1);
	mstack.push(101);
	sleep(1);
	mstack.push(5);

	std::cout << CYAN << "Current stack state after more mutations: " << RESET << std::endl;

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;
	std::cout << YELLOW << "Intern is now wondering if there's a mutant creature lurking in the stack!" << RESET << std::endl;
	sleep(2);

	std::cout << RED << "Popping a value off the stack... Let's see what's left!" << RESET << std::endl;
	sleep(1);
	mstack.pop();

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
		sleep(1);
	}

	std::cout << std::endl;

	std::cout << WHITE << "Experiment complete. The intern's work here is done. Or is it?" << RESET << std::endl;
	sleep(2);

	return 0;
}
   
/*
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
*/
/*
int main()
{
    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.front() << std::endl;
	mlist.pop_front();
    std::cout << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();

    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}
*/
