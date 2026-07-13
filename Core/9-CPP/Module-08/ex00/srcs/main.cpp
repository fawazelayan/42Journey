#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

// Test easyfind with std::vector<int>
void testVector()
{
	std::cout << "--- Testing std::vector<int> ---" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 99);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

// Test easyfind with std::list<int>
void testList()
{
	std::cout << "--- Testing std::list<int> ---" << std::endl;
	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(200);
	lst.push_back(300);
	try
	{
		std::list<int>::iterator it = easyfind(lst, 200);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	testVector();
	testList();
	return 0;
}