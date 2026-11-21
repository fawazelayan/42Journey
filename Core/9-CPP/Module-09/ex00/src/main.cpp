#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange exchange;

		exchange.loadDatabase("data.csv");
		exchange.processInput(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}