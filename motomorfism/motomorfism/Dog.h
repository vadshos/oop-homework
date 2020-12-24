#pragma once
#include "DomesticAnimal.h"

class Dog : public DomesticAnimal
{
public:
	Dog(const size_t age = 1, const double weight = 0.1, const std::string  owner = "Vasya", const std::string breed = "No breed");
	void sound() const override;
	void eat() const override;
	void type() const override;
	void print() const override;

private:
	std::string breed;
};

