#include <iostream>
#include "iter.hpp"

// Test function to print an element
template <typename T>
void printElement(const T& element)
{
	std::cout << element << " ";
}

// Test function to increment an integer element
void incrementElement(int& element)
{
	element += 1;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original intArray: ";
	::iter(intArray, intArrayLen, printElement<int>);
	std::cout << std::endl;

	std::cout << "Incrementing intArray..." << std::endl;
	::iter(intArray, intArrayLen, incrementElement);

	std::cout << "Modified intArray: ";
	::iter(intArray, intArrayLen, printElement<int>);
	std::cout << std::endl;

	std::string strArray[] = {"hello", "world", "templates"};
	std::size_t strArrayLen = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "strArray: ";
	::iter(strArray, strArrayLen, printElement<std::string>);
	std::cout << std::endl;

	const int constArray[] = {10, 20, 30};
	std::size_t constArrayLen = sizeof(constArray) / sizeof(constArray[0]);

	std::cout << "constArray: ";
	::iter(constArray, constArrayLen, printElement<int>);
	std::cout << std::endl;

	return 0;
}