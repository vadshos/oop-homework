#include "WildAnimal.h"

void WildAnimal::type() const
{
	std::cout << "It is  wild animal" << std::endl;
}

void WildAnimal::print() const
{
	Animal::print();
	live();
}

