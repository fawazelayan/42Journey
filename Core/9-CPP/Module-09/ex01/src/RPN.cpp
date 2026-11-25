#include "RPN.hpp"
#include <climits>
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
int RPN::evaluate(const std::string& expression)
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
			double num2 = numbers.top();
			numbers.pop();
			double num1 = numbers.top();
			numbers.pop();
			double result;
			if (token == "+")
				result = num1 + num2;
			else if (token == "-")
				result = num1 - num2;
			else if (token == "*")
				result = num1 * num2;
			else if (num2 == 0)
				throw std::runtime_error("Error");
			else
				result = num1 / num2;
			// the result must fit in an int
			if (result > INT_MAX || result < INT_MIN)
				throw std::runtime_error("Error");
			numbers.push(static_cast<int>(result));
		}
		else
			throw std::runtime_error("Error");
	}
	if (numbers.size() != 1)
		throw std::runtime_error("Error");
	return numbers.top();
}