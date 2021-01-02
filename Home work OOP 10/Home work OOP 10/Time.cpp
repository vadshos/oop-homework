#include "Time.h"

Time::Time(const size_t& hour, const size_t& min)
{
	setHour(hour);
	setMin(min);
}

Time::Time(const Time& obj)
{
	this->hour = obj.hour;
	this->min = obj.min;
}

void Time::setTime(const size_t& hour, const size_t& min)
{
	setHour(hour);
	setMin(min);
}

void Time::setHour(const size_t& hour)
{
	if (hour >= 0 && hour < 24)
		this->hour = hour;
	else
		this->hour = 00;
}

void Time::setMin(const size_t& min)
{
	if (min <= 60 && min > 0)
		this->min = min;
	else
		this->min = 00;
}

size_t Time::getHour() const
{
	return hour;
}

size_t Time::getMin() const
{
	return min;
}

void Time::operator=(const Time& obj)
{
	this->hour = obj.hour;
	this->min = obj.min;
}



std::ostream& operator<<(std::ostream& os, const Time& obj)
{
	if(obj.hour==0)
		if (obj.min == 0) {
			os << "Time 00:00" << std::endl;
			return os;
		}
		else {
			if (obj.min < 10) {
				os << "Time 00:0" << obj.min << std::endl;
				return os;
			}
			else {
				os << "time 00:" << obj.min << std::endl;
				return os;
			}
			
		}
	if (obj.min < 10) {
		if (obj.hour > 10) {
			os << obj.hour << ":0" << obj.min << std::endl;
			return os;
		}
		else {
			os <<"0" <<obj.hour << ":0" << obj.min << std::endl;
		}
	}
	else {
		if (obj.hour > 10) {
			os << obj.hour << ":" << obj.min << std::endl;
			return os;
		}
		else {
			os << "0" << obj.hour << ":" << obj.min << std::endl;
		}
	}
}

bool& operator==(const Time& objFirst,const Time& objSecond)
{
	bool isTrue = (objFirst.hour == objSecond.hour && objSecond.min == objFirst.min);
	return isTrue;
}

bool operator<(const Time& objFirst, const Time& objSecond)
{
	if (objFirst.hour < objSecond.hour) {
		return false;
	}
	else {
		if (objFirst.min < objSecond.min) {
			return false;
		}
	}
	return true;
}
