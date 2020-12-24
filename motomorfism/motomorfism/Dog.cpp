#include "Dog.h"

Dog::Dog(const size_t age, const double weight, const std::string owner, const std::string breed) : DomesticAnimal(age,weight,owner)
{
}

void Dog::sound() const
{
	std::cout << "Wow - wow" << std::endl;
}

void Dog::eat() const
{
	std::cout << "It likes meat" << std::endl;
}

void Dog::type() const
{
	DomesticAnimal::type();
	std::cout << " - Dog ";
}

void Dog::print() const
{
	std::cout << "Breed of dog " << breed << std::endl;
	DomesticAnimal::print();
	return;
}
