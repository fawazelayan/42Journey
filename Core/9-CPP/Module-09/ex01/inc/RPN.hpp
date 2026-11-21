#ifndef RPN_HPP
# define RPN_HPP

#include <list>
#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<long, std::list<long> >	numbers;

	public:
		// Constructors & Destructor
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		// RPN Operations
		long evaluate(const std::string& expression);
};

#endif