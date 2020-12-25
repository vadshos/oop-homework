#pragma once
#include "Shooter.h"

class Range :virtual public Shooter
{
protected:
	Range(const size_t& countAmunition);
	void addAmunition(const size_t& countAmunition);
	void shot();
};



