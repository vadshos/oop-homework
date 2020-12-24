#pragma once
#include "Animal.h"

class DomesticAnimal : public Animal
{
public:
	DomesticAnimal(const size_t age = 1, const double weight = 0.1,const std::string  owner = "Vasya");
	void type() const override;
	void print() const override;
	
private:
	std::string owner;
};

