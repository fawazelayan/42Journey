#include "MutantStack.hpp"
#include <iostream>
#include <list>

// Test using MutantStack (wrapped in try-catch to handle the stub throws)
void testMutantStack()
{
	std::cout << "--- Testing MutantStack ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	try
	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Iterator access exception: " << e.what() << std::endl;
	}
	std::stack<int> s(mstack);
	std::cout << "Successfully copied to std::stack" << std::endl;
}

// Test using std::list (swapping MutantStack for std::list to show identical output)
void testListComparison()
{
	std::cout << "--- Testing std::list (equivalent code) ---" << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	testMutantStack();
	testListComparison();
	return 0;
}