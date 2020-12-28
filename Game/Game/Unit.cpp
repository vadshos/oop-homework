#include "Unit.h"

Unit::Unit(const std::string& nameUnit,const size_t& health, const size_t& damage, const double& dodge) {
	setHealth(health);
	setDamege(damage);
	setDodge(dodge);
	setNameUnit(nameUnit);
	levelUnit = 1;
}
void Unit::setHealth(const size_t& health)
{
	
	if (health > 0)
		this->health = health;
}

void Unit::setDamege(const size_t& damage)
{
	if (damage > 0)
		this->damege = damage;
}

void Unit::setDodge(const double& dodge)
{
	if (dodge >= 0 && dodge <= 100)
		this->dodge = dodge;
}

void Unit::setNameUnit(const std::string& nameUnit)
{
	if (!nameUnit.empty())
		this->nameUnit = nameUnit;
}

size_t Unit::getHealth() const
{
	return health;
}

size_t Unit::getDamege() const
{
	return damege;
}

double Unit::getDodge() const
{
	return dodge;
}

std::string Unit::getNameUnit() const
{
	return nameUnit;
}

void Unit::upLevel()
{
	if (levelUnit < 6) {
		++levelUnit;
		setDamege(damege * levelUnit);
		setHealth(health * levelUnit);
	}
	else {
		std::cout << "Can't update max level" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Unit& obj)
{
	os << "Name unit : " << obj.nameUnit << std::endl;
	os << "Health : " << obj.health << std::endl;
	os << "Damege : " << obj.damege << std::endl;
	os << "Dodge : " << obj.dodge<<"%" << std::endl;
	os << "Level unit : " << obj.levelUnit << std::endl;
	return os;
}
