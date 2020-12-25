#include "Archer.h"


Archer::Archer(const size_t& countAmunition) : Shooter("arch",countAmunition)
{
}

void Archer::addAmunition(const size_t& countAmunition)
{
	Shooter::setCount(countAmunition);
}

void Archer::shot()
{
	Shooter::shot();
}
