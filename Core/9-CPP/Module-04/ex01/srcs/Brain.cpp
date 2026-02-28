#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default called\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}
Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}
Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy called\n";
	*this = other;
}
Brain &Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this -> ideas[i] = other.ideas[i];
	}
	std::cout << "Brain assignment called\n";
	return *this;
}
