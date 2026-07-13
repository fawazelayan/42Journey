#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

// Test the standard example from the subject
void testSubjectExample()
{
	std::cout << "--- Subject Example Test ---" << std::endl;
	std::cout << "Expected Output:" << std::endl;
	std::cout << "  Shortest = 2, Longest = 14" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Actual Output:" << std::endl;
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "  Exception: " << e.what() << std::endl;
	}
}

// Test calling span functions when there are insufficient elements
void testEmptyOrSingleElementExceptions()
{
	std::cout << "\n--- Insufficient Elements Exception Test ---" << std::endl;
	std::cout << "Expected Output:" << std::endl;
	std::cout << "  Empty Span Exception: Span contains fewer than two elements" << std::endl;
	std::cout << "  Single Element Exception: Span contains fewer than two elements" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Actual Output:" << std::endl;
	Span spEmpty = Span(5);
	try
	{
		spEmpty.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "  Empty Span Exception: " << e.what() << std::endl;
	}

	Span spOne = Span(5);
	try
	{
		spOne.addNumber(42);
		spOne.longestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "  Single Element Exception: " << e.what() << std::endl;
	}
}

// Test capacity limits by exceeding the maximum size
void testCapacityException()
{
	std::cout << "\n--- Capacity Exception Test ---" << std::endl;
	std::cout << "Expected Output:" << std::endl;
	std::cout << "  Exception: Span is already full" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Actual Output:" << std::endl;
	Span sp = Span(3);
	try
	{
		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
		sp.addNumber(40);
	}
	catch (const std::exception& e)
	{
		std::cout << "  Exception: " << e.what() << std::endl;
	}
}

// Test filling a span using iterator range insertion
void testRangeInsertion()
{
	std::cout << "\n--- Range Insertion Test ---" << std::endl;
	std::cout << "Expected Output:" << std::endl;
	std::cout << "  Shortest = 1, Longest = 9" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Actual Output:" << std::endl;
	Span sp = Span(10);
	int arr[] = {1, 3, 4, 7, 8, 10};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	try
	{
		sp.addNumber(vec.begin(), vec.end());
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "  Exception: " << e.what() << std::endl;
	}
}

// Test span functionality with 20,000 elements
void testLargeSpan()
{
	std::cout << "\n--- Large Scale Test (20,000 elements) ---" << std::endl;
	std::cout << "Expected Output:" << std::endl;
	std::cout << "  Successfully filled 20,000 elements." << std::endl;
	std::cout << "  Shortest span: 3" << std::endl;
	std::cout << "  Longest span: 59997" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Actual Output:" << std::endl;
	Span sp = Span(20000);
	std::vector<int> bigVector;
	bigVector.reserve(20000);
	for (int i = 0; i < 20000; i++)
		bigVector.push_back(i * 3);
	try
	{
		sp.addNumber(bigVector.begin(), bigVector.end());
		std::cout << "  Successfully filled 20,000 elements." << std::endl;
		std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "  Exception: " << e.what() << std::endl;
	}
}

int main()
{
	testSubjectExample();
	testEmptyOrSingleElementExceptions();
	testCapacityException();
	testRangeInsertion();
	testLargeSpan();
	return 0;
}