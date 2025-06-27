#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iomanip>
# include <string>

# define RED	"\033[1;31m"
# define GRN	"\033[1;32m"
# define YLW	"\033[1;33m"
# define BLU	"\033[1;34m"
# define PRP	"\033[1;35m"
# define CYN	"\033[1;36m"
# define RST	"\033[0m"

void	displayInfo(const std::string& first, const std::string& last,
					const std::string& nick, const std::string& num,
					const std::string& secret);
void	drawTable(const int index,
					const std::string& first, const std::string& last,
					const std::string& nick);

int	searchValidIndex(int& index, const int count);

std::string	addValidInfo(std::string prompt);
std::string	truncate(const std::string& str);

#endif