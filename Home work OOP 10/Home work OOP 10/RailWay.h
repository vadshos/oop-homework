#pragma once
#include"Train.h"
#include <algorithm>
#include<fstream>

class RailWay
{
public:
	RailWay();
	 ~RailWay();
	void addTrain(const Train& obj);
	void printSomeTrain(const size_t& index) const ;
	void popSomeTrain(const size_t& index);
	void editTrain(const int& index = -1, const std::string& destinationPlace = "", const Time& arriveTime = Time());
	friend std::ostream& operator<<(std::ostream& os, const RailWay& obj);
private:
	std::vector<Train> railWay;
};

