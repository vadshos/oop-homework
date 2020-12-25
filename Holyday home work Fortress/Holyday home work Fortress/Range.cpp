#include "Range.h"


Range::Range(const size_t& countAmunition) : Shooter("arch", countAmunition)
{
}

void Range::addAmunition(const size_t& countAmunition)
{
	Shooter::setCount(countAmunition);
}

void Range::shot()
{
	Shooter::shot();
}
