#include "Sed.hpp"

int main(int ac, char **av)
{
	int validation_err = 0;

	if (is_invalid_input(ac - 1, av + 1, validation_err))
		return (validation_err);

	std::string buffer;
	std::string oldContent;
	std::string oldFileName(av[1]);
	std::ifstream inFile(oldFileName.c_str());
	while (getline(inFile, buffer))
		oldContent += buffer + '\n';
	inFile.close();

	size_t pos = 0;
	size_t found = 0;
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::string newContent;
	while ((found = oldContent.find(s1, pos)) != std::string::npos)
	{
		newContent.append(oldContent.substr(pos, found - pos));
		newContent.append(s2);
		pos = found + s1.length();
	}
	newContent.append(oldContent.substr(pos));

	std::string newFileName = oldFileName + ".replace";
	bool fileExist = false;
	{
		std::ifstream test(newFileName.c_str());
		fileExist = test.is_open();
	}
	std::ofstream outFile(newFileName.c_str());
	if (!outFile.is_open())
	{
		std::cout << "\nError: can't create or write to file.\n\n";
		return 5;
	}
	if (fileExist)
		std::cout << "\nWarning: overwriting the file.\n\n";
	outFile << newContent;

	return 0;
}