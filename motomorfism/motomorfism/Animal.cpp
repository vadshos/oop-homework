#include "Animal.h"

Animal::Animal(const size_t age, const double weight) 
{
	setAge(age);
	setWeight(weight);
}

void Animal::setAge(const size_t age)
{
	if (age >= 0 && age < 25) {
		this->age = age;
	}
}

void Animal::setWeight(const double weight)
{
	if (weight > 0 && weight < 10000)
	{
		this->weight = weight;
	}
}

void Animal::print() const
{
	type();
	std::cout << "Age : " << age << std::endl;
	std::cout << "Weigth : " << weight << std::endl;
	eat();
	sound();
}
