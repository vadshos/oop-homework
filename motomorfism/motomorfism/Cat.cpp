#include "Cat.h"

#include "Dog.h"



Cat::Cat(const size_t age, const double weight, const std::string owner, const std::string breed, const double WoolLength) : DomesticAnimal(age, weight, owner)
{
}

void Cat::sound() const
{
	std::cout << "Mew - mew" << std::endl;
}

void Cat::eat() const
{
	std::cout << "It likes mouse" << std::endl;
}

void Cat::type() const
{
	DomesticAnimal::type();
	std::cout << " - Cat ";
}

void Cat::print() const
{
	std::cout << "Breed of cat " << breed << std::endl;
	DomesticAnimal::print();
	return;
}

