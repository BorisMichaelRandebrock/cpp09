/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:30:41 by brandebr          #+#    #+#             */
/*   Updated: 2024/12/04 15:09:38 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &cpy) {
	this->_stack = cpy._stack;
}

RPN &RPN::operator=(const RPN &cpy) {
	if (this != &cpy)
		this->_stack = cpy._stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const {
	return token == "+" || token == "-" || token == "*" || token == "/"; 
} 

double	RPN::calculate(double a, double b, const std::string &op) const {
	if (!op.compare("+"))
		return (a + b);
	if (!op.compare("-"))
		return (a - b);
	if (!op.compare("*"))
		return a * b;
	if (!op.compare("/")) {
		if (a == 0)
			throw std::runtime_error("Division by zero");
		return a / b;
	}
	throw std::runtime_error("Invalid operator");
}

double RPN::evaluateRPN(const std::string &expression) {
	std::stack<double>	stack;
	std::stringstream	ss(expression);
	std::string 		token;

	while (ss >> token) {
		if (isdigit(token[0])) {
			stack.push(::strtod(token.c_str(), NULL));
		} else if (isOperator(token)) {
			if (stack.size() < 2)
				throw std::runtime_error("Insufficient operands");
			double operand2 = stack.top(); stack.pop();
            double operand1 = stack.top(); stack.pop();
            stack.push(calculate(operand1, operand2, token));
		} else {
			throw std::runtime_error("Invalid token");
		}
	}
	if (stack.size() != 1) throw std::runtime_error("Invalid expression");
    return stack.top();
}


