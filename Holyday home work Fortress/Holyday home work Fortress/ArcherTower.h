#pragma once
#include "Range.h"
#include "Archer.h"

class ArcherTower :public Range, public Archer
{
protected:
	ArcherTower(const size_t& countAmunition);
	void shotArch();
	void shotRange();
	
};

