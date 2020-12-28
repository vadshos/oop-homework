#include "Team.h"

void Team::Uplevel()
{
	for (auto& v : team) {
		v.upLevel();
	}
}
Team::Team(const std::string& nameTeam)
{
	setNameTeam(nameTeam);
	
	randomUnit();
}

std::vector<std::string> Team::nameTeams;

void Team::setNameTeam(const std::string nameTeam)
{
	bool isFound = false;
	for (auto& v : nameTeams) {
		if (v == nameTeam) {
			isFound = true;
		}
	}
	if (!isFound) {
		this->nameTeam = nameTeam;
		nameTeams.push_back(nameTeam);
	}
	else {
		std::cout << "Name is busy . Enter new name" << std::endl;
		std::string temp;
		getline(std::cin, temp);
		setNameTeam(temp);
	}
}

void Team::randomUnit()
{
	srand(time(NULL));
	for ( size_t i = 0; i <countUnit; i++)
	{
		size_t a = rand() % 3;
		if (a == 0) {
			team.push_back(Swordsman());
		}
		else if (a == 1) {
			team.push_back(Archer());
		}
		else {
			team.push_back(Mage());
		}
	}

}

bool Team::isNoKillUnit() const
{
	for (auto& v : this->team) {
		if (v.getHealth() != 0) {
			return true;
		}
	}
	return false;
}

std::string Team::getName() const
{
	return nameTeam;
}

size_t Team::getCountTeam() const
{
	return countUnit;
}

std::ostream& operator<<(std::ostream& os, const Team& obj)
{
	os << "Name team : " <<obj.nameTeam<<std::endl;
	os << std::endl;
	for (auto& v : obj.team) {
		os << v << std::endl;
	}
	return os;
}
