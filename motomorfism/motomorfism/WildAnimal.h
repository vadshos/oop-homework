#pragma once
#include "Animal.h"

class WildAnimal : public Animal
{
	WildAnimal(const size_t age = 1, const double weight = 0.1);
	void type() const override;
	void print() const override;
	virtual void live() const abstract;

private:
	
};

