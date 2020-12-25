#pragma once
#include "Shooter.h"

class Catapult : public Shooter
{
public:
	Catapult(const size_t& countAmunition);
	void addAmunition(const size_t& countAmunition);
	void shot();
};

