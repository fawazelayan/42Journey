#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	private:
		unsigned int		n;
		std::vector<int>	elements;

	public:
		// Constructors & Destructor
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		// Member Functions
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		template <typename InputIterator>
		void addNumber(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				this -> addNumber(*first);
				first++;
			}
		}

		// Exception Classes
		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Span is already full";
				}
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Span contains fewer than two elements";
				}
		};
};

#endif