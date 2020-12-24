#include "DomesticAnimal.h"
#include <iostream>

DomesticAnimal::DomesticAnimal(const size_t age, const double weight, const std::string owner) : Animal(age,weight),owner(owner)
{
	
}

void DomesticAnimal::type() const
{
	std::cout << "It is  domestic animal" << std::endl;
}

void DomesticAnimal::print() const
{
	std::cout << "Owner : " << owner << std::endl;
    Animal::print();
}
