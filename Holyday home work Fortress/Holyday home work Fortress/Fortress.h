#pragma once
#include "ArcherTower.h"
#include "Catapult.h"

class Fortress : protected ArcherTower, protected Catapult
{
public:
	friend struct Battle;
	Fortress(const size_t& AmunitionArcherTower, const size_t& AmunitionCatapult,const double& WallThickness = 1);
	void shotArcher();
	void shotRange();
	void shotCatapult();
	void addAmunitionTower(const size_t& Amunition);
	void addAmunitionCatapult(const size_t& Amunition);
	void setWallThickness(const double& WallThickness);
	void updateLever();

private:
	double ConditionofTheGate;
	double WallThickness;
	size_t levelFortess ;
};

inline void Fortress::updateLever()
{
	levelFortess++;
}