#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		double value = std::atof(argv[i]);
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos
			|| value <= 0 || value > INT_MAX)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}
	PmergeMe sorter;

	std::clock_t start = std::clock();
	std::vector<int> vec;
	for (int i = 1; i < argc; i++)
		vec.push_back(std::atoi(argv[i]));
	sorter.sortVector(vec);
	double vecTime = (std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC;

	start = std::clock();
	std::deque<int> deq;
	for (int i = 1; i < argc; i++)
		deq.push_back(std::atoi(argv[i]));
	sorter.sortDeque(deq);
	double deqTime = (std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "Before:";
	for (int i = 1; i < argc; i++)
		std::cout << " " << std::atoi(argv[i]);
	std::cout << std::endl << "After:";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << " " << vec[i];
	std::cout << std::endl << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << deqTime << " us" << std::endl;
	return 0;
}