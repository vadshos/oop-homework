#include "Bus.h"
size_t Bus::numberBus = 0;

Bus::Bus(const std::string& fullName, const size_t& numberRoad)
{
	++numberBus;
	id = numberBus;
	setFullName(fullName);
	setNumberRoad(numberRoad);
}

Bus::Bus(const Bus& obj)
{
	*this = obj;
	
}

void Bus::setFullName(const std::string& fullName)
{
	size_t found = fullName.find(".");
	if (found != std::string::npos) {
		 found = fullName.find(".", found+1);
		if (found != std::string::npos) {
			
			
				this->fullName = fullName;
			
		}
	}
	
}

void Bus::setNumberRoad(const size_t& numberRoad)
{
	if (numberRoad > 0) {
		this->numberRoad = numberRoad;
	}
}

Bus& Bus::operator=(const Bus& obj)
{
	setFullName(obj.fullName);
	setNumberRoad(obj.numberRoad);
	id = obj.id;
	return *this;
}

bool Bus::operator==(const Bus& obj)
{
	return false;
}

std::ostream& operator<<(std::ostream& os, Bus obj)
{
	os << "Full name : " << obj.fullName << std::endl;
	os << "Number bus : " << obj.id << std::endl;
	os << "Number roude : " << obj.numberRoad << std::endl;
	os << std::endl;
	return  os;
}
