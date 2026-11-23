#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& other)
	: numbers(other.numbers) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		numbers = other.numbers;
	return *this;
}

RPN::~RPN() {}

// compute the expression
long RPN::evaluate(const std::string& expression)
{
	std::istringstream stream(expression);
	std::string token;

	while (!numbers.empty())
		numbers.pop();
	while (stream >> token)
	{
		if (token.length() != 1)
			throw std::runtime_error("Error");
		if (token[0] >= '0' && token[0] <= '9')
			numbers.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (numbers.size() < 2)
				throw std::runtime_error("Error");
			long num2 = numbers.top();
			numbers.pop();
			long num1 = numbers.top();
			numbers.pop();
			if (token == "+")
				numbers.push(num1 + num2);
			else if (token == "-")
				numbers.push(num1 - num2);
			else if (token == "*")
				numbers.push(num1 * num2);
			else if (num2 == 0)
				throw std::runtime_error("Error");
			else
				numbers.push(num1 / num2);
		}
		else
			throw std::runtime_error("Error");
	}
	if (numbers.size() != 1)
		throw std::runtime_error("Error");
	return numbers.top();
}