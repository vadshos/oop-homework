#include "Catapult.h"




Catapult::Catapult(const size_t& countAmunition) : Shooter("stone", countAmunition)
{
}

void Catapult::addAmunition(const size_t& countAmunition)
{
	Shooter::setCount(countAmunition);
}

void Catapult::shot()
{
	Shooter::shot();
}

