#include "RailWay.h"

RailWay::RailWay()
{
	std::ifstream fout;
	fout.open("DateBase.txt");
	std::string tempDestination;
	size_t tempHour;
	size_t tempMin;
	if (fout.is_open()) {
		while (!fout.eof()) {
			fout >> tempDestination;
			fout >> tempHour;
			fout >> tempMin;
			if (tempDestination != "") {
				Time t(tempHour, tempMin);
				Train tempObj(tempDestination, t);
				railWay.push_back(tempObj);
			}
		}
	}
	
}

RailWay::~RailWay()
{
	std::ofstream out;			
	out.open("DateBase.txt");
	if (out.is_open())
	{
		for (auto& v : railWay)
		{
			out << v.getDestinationPlace()<<std::endl;
			out << v.getArriveTime().getHour() << std::endl;
			out << v.getArriveTime().getMin() << std::endl;


		}
	}
	
}

void RailWay::addTrain(const Train& obj)
{
	railWay.push_back(obj);
	
}

void RailWay::printSomeTrain(const size_t& index) const
{
	if(index <= railWay.size())
	std::cout << *(railWay.begin() + index)<<std::endl;
}

void RailWay::popSomeTrain(const size_t& index)
{
	if (index <= railWay.size())
		railWay.erase(railWay.begin()+index);
}

void RailWay::editTrain(const int& index, const std::string& destinationPlace, const Time& arriveTime)
{
	if (index >= 0) {
		if (destinationPlace == "") {
			(*(railWay.begin() + index)).setArriveTime(arriveTime);
		}
		else if(arriveTime == Time()){
			(*(railWay.begin() + index)).setDestinationPlace(destinationPlace);
		}
		else if (arriveTime == Time() && destinationPlace == "") {
			(*(railWay.begin() + index)).setDestinationPlace(destinationPlace);
			(*(railWay.begin() + index)).setArriveTime(arriveTime);

		}
	}
}



std::ostream& operator<<(std::ostream& os, const RailWay& obj)
{

	for (auto& v : obj.railWay) {
		os << "##############" << std::endl;
		os << v << std::endl;
	}
	return os;
}
