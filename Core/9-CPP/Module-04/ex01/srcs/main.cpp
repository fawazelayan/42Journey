#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int size = 10;
	Animal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i == size / 2)
			std::cout << "\n\n";
		if (i < size / 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << "\n\n";
	for (int i = 0; i < size; i++)
	{
		if (i == size / 2)
			std::cout << "\n\n";
		delete animals[i];
	}
	std::cout << "\n\n";
	Dog copied;
	{
		Dog copy = copied;
	}
}