#include "Train.h"

size_t Train::countTrain = 0;
std::vector<std::string> Train::namePlace;
std::vector<Time> Train::timeArrivePlace;

Train::Train( std::string destinationPlace,  Time& arriveTime) 
{
	if (isCanSet(destinationPlace, arriveTime)) {
		setDestinationPlace(destinationPlace);
		setArriveTime(arriveTime);
		namePlace.push_back(destinationPlace);
		timeArrivePlace.push_back(arriveTime);
		++countTrain;
		number = countTrain;
	}
	
	
}

bool Train::isCanSet(const std::string& destinationPlace, const Time& arriveTime)
{
	size_t i = 0;
	for (auto& v : namePlace) {
		if (v == destinationPlace) {
			if (*(timeArrivePlace.begin() + i) == arriveTime) {
				return false;
			}
		}
		++i;
	}
	return true;
}

void Train::setDestinationPlace(const std::string& destinationPlace)
{
	if (!destinationPlace.empty())
		this->destinationPlace = destinationPlace;
}

void Train::setArriveTime(const Time& arriveTime)
{
	this->arriveTime = arriveTime;
}

std::string Train::getDestinationPlace() const
{
	return destinationPlace;
}

Time Train::getArriveTime() const
{
	return arriveTime;
}

std::ostream& operator<<(std::ostream& os, const Train& obj)
{
	os << "Number train : " << obj.number << std::endl;
	os << "Destination place : " << obj.destinationPlace << std::endl;
	os << "Arrive time : " << obj.arriveTime ;
	return os;
}

bool& operator<(const Train& objFirst, const Train& objSecond)
{
	bool isTrue = objFirst.arriveTime < objSecond.arriveTime;
	return isTrue;
}
