#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
j->makeSound();
i->makeSound(); //will output the cat sound!
meta->makeSound();
delete meta;
delete i;
delete j;

std::cout << "\n\n";

const WrongAnimal* meta2 = new WrongAnimal();
const WrongAnimal* j2 = new WrongDog();
const WrongAnimal* i2 = new WrongCat();
std::cout << j2->getType() << " " << std::endl;
std::cout << i2->getType() << " " << std::endl;
j2->makeSound();
i2->makeSound(); //will output the cat sound!
meta2->makeSound();
delete meta2;
delete i2;
delete j2;
}