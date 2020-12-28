#pragma once
#include"Team.h"
class GAME
{
public:
	void Battle(Team& firstTeam,Team& secondTeam);
	void searchForAnOpponent(Team& firstTeam,Team& secondTeam);
private:
	bool batleTwo(Unit& firstUnit,Unit& secondUnit);
	bool shot(Unit& unitFirst, Unit& unitSecond,const size_t& tr);
};

