#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	rates;

		// Helpers
		static bool isValidDate(const std::string& date);
		static bool parseValue(const std::string& text, double& value);
		void processLine(const std::string& line) const;

	public:
		// Constructors & Destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		// Exchange Operations
		void loadDatabase(const std::string& path);
		void processInput(const std::string& path) const;
};

#endif