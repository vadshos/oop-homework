#include "Shooter.h"

void Shooter::shot()
{
	if (countAmunition != 0) {
		std::cout << NameAmunition << " shot "  << std::endl;
		--countAmunition;
	}
	else {
		std::cout << NameAmunition << " is over" << std::endl;
	}
}

Shooter::Shooter(const std::string& NameAmunition, const size_t& countAmunition)
{
	addAmunition(NameAmunition, countAmunition);
}

void Shooter::addAmunition(const std::string& NameAmunition, const size_t& countAmunition)
{
	if (!NameAmunition.empty()) {
		this->NameAmunition = NameAmunition;
		this->countAmunition = countAmunition;
	}
}



size_t Shooter::getCount() const
{
	return countAmunition;
}

void Shooter::setCount(const size_t& countAmunition)
{
	
		this->countAmunition += countAmunition;
	
}
