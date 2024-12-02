/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:19:17 by brandebr          #+#    #+#             */
/*   Updated: 2024/12/02 17:37:15 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <stdexcept>
# include <cstdlib>
# include <cctype>
# include <iostream>

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

class RPN {
	public:
		RPN();
//		RPN(const RPN &cpy);
//		RPN &operator=(const RPN &cpy);
		~RPN();

		double 	evaluateRPN(const std::string &epression);
		bool 	isOperator(const std::string &token) const;
		double	calculate(double a, double b, const std::string &op) const; 
};

#endif
