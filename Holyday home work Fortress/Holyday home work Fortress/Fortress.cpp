#include "Fortress.h"



Fortress::Fortress(const size_t& AmunitionArcherTower, const size_t& AmunitionCatapult, const double& WallThickness)
	: ArcherTower(AmunitionArcherTower), ArcherTower::Shooter("arch", AmunitionArcherTower), Catapult(AmunitionCatapult)
{
	setWallThickness(WallThickness);
	levelFortess = 1;
}

void Fortress::shotArcher()
{
	for (size_t i = 0; i < 3; ++i) {
		ArcherTower::shotArch();
	}
}

void Fortress::shotRange()
{
	
	for (size_t i = 0; i < 2; ++i) {
		ArcherTower::shotRange();
	}
}
void Fortress::shotCatapult()
{
	
		Catapult::shot();
	
}

void Fortress::addAmunitionTower(const size_t& Amunition)
{
	
	ArcherTower::setCount(Amunition);
}
void Fortress::addAmunitionCatapult(const size_t& Amunition)
{
	Catapult::Shooter::setCount(Amunition);
}

void Fortress::setWallThickness(const double& WallThickness)
{
	if (WallThickness > 0 && WallThickness < 15) {
		this->WallThickness = WallThickness;
	}
}
