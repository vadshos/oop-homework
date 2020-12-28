#pragma once
#include<iostream>	
#include<vector>
#include<string>

#include<ctime>
#include "Unit.h"
#include "Mage.h"
#include "Archer.h"
#include "Swordsman.h"

class Team 
{
public:
	friend class GAME;
	Team(const std::string& nameTeam = "NoName");
	bool isNoKillUnit() const ;
	friend std::ostream& operator<<(std::ostream& os, const Team& obj);
	std::string getName() const;
	size_t getCountTeam() const;
	void Uplevel();
private:
	void randomUnit();
	std::vector<Unit> team; 
	void setNameTeam(const std::string nameTeam);
	static const size_t countUnit = 3;
	std::string nameTeam;
	static std::vector<std::string> nameTeams;

};

