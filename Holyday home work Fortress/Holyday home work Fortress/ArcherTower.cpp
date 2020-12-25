#include "ArcherTower.h"

ArcherTower::ArcherTower(const size_t& countAmunition)
	:  Archer(0), Range(0) ,Shooter("arch",countAmunition)
{}

void ArcherTower::shotArch()
{
  Archer::shot();
}

void ArcherTower::shotRange()
{
	Range::shot();
}
