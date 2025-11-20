#include "Sed.hpp"

int is_invalid_input(int ac, char **av, int &err)
{
	if (ac != 3)
	{
		std::cout << "\nUsage: ./sed <file_name> <pattern> <pattern_replace>\n\n";
		err = 1;
		return err;
	}

	std::string filename(av[0]);
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open())
	{
		std::cout << "\nError: can't open file: " << filename << "\n\n";
		err = 2;
		return err;
	}

	if (inFile.peek() == EOF)
	{
		std::cout << "\nError: file is empty: " << filename << "\n\n";
		err = 3;
		return err;
	}

	inFile.close();

	std::string s1 = av[1];
	if (s1.empty())
	{
		std::cout << "\nError: pattern can't be empty.\n\n";
		err = 4;
		return err;
	}

	return 0;
}