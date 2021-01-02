#pragma once
#include <iostream>
#include <vector>
#include <string>
#include"Time.h"

class Train
{
public:
	
	Train(std::string destinationPlace , Time& arriveTime);
	bool isCanSet(const std::string& destinationPlace, const Time& arriveTime);
	void setDestinationPlace(const std::string& destinationPlace);
	void setArriveTime(const Time& arriveTime);
	friend std::ostream& operator<<(std::ostream& os, const Train& obj);
	friend bool& operator<( const Train& objFirst,const Train& objSecond);
	std::string getDestinationPlace() const;
	Time getArriveTime() const;

private:
	std::string destinationPlace;
	Time arriveTime;
	static size_t countTrain;
	size_t number;
	static std::vector<std::string> namePlace;
	static std::vector<Time> timeArrivePlace;

};;

