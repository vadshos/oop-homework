#pragma once
#include "DomesticAnimal.h"
class Cat : public DomesticAnimal
{
public:
	Cat(const size_t age = 1, const double weight = 0.1, const std::string  owner = "Vasya", const std::string breed = "No breed",const double  WoolLength = 0);
	void sound() const override;
	void eat() const override;
	void type() const override;
	void print() const override;

private:
	std::string breed;
	double  WoolLength;

};

