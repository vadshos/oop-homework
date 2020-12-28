#pragma once
#include <iostream>
#include <vector>




class  Unit  
{
public:
	Unit(const std::string& nameUnit = "Unit",const size_t& health=1,const size_t& damage=1,const double& dodge=0);
	void setHealth(const size_t& health);
	void setDamege(const size_t& damage);
	void setDodge(const double& dodge);
	void setNameUnit(const std::string& nameUnit);
	size_t getHealth() const;
	size_t getDamege() const;
	double getDodge() const;
	std::string getNameUnit() const;

	void upLevel();
	friend std::ostream& operator<<(std::ostream& os, const Unit& obj);

protected:
	std::string nameUnit;
	size_t health;
	size_t damege;
	double dodge;
	size_t levelUnit;
};

