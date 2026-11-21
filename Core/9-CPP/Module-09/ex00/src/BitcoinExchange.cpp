#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: rates(other.rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		rates = other.rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// date must be YYYY-MM-DD and a real day
bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-'
		|| date.find_first_not_of("0123456789-") != std::string::npos
		|| std::count(date.begin(), date.end(), '-') != 2)
		return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonth[1] = 29;
	if (month < 1 || month > 12)
		return false;
	return day >= 1 && day <= daysInMonth[month - 1];
}

// the whole text must be a number
bool BitcoinExchange::parseValue(const std::string& text, double& value)
{
	std::istringstream stream(text);

	stream >> value;
	return !stream.fail() && stream.eof();
}

// load data.csv into the map
void BitcoinExchange::loadDatabase(const std::string& path)
{
	std::ifstream file(path.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t comma = line.find(',');
		rates[line.substr(0, comma)] = std::atof(line.substr(comma + 1).c_str());
	}
}

// read the input file line by line
void BitcoinExchange::processInput(const std::string& path) const
{
	std::ifstream file(path.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	if (std::getline(file, line) && line != "date | value")
		processLine(line);
	while (std::getline(file, line))
		processLine(line);
}

// check one line and print the result
void BitcoinExchange::processLine(const std::string& line) const
{
	size_t separator = line.find(" | ");
	std::string date = line.substr(0, separator);
	double value;

	if (separator == std::string::npos || !isValidDate(date)
		|| !parseValue(line.substr(separator + 3), value))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	// first date after ours, then go back one
	std::map<std::string, double>::const_iterator it = rates.upper_bound(date);

	if (value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (value > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else if (it == rates.begin())
		std::cout << "Error: bad input => " << date << std::endl;
	else
	{
		--it;
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
}