#pragma once
#include<iostream>
class Time
{
public:
	Time() = default;
	Time(const size_t& hour, const size_t& min);
	Time(const Time& obj);

	void setTime(const size_t & hour,const size_t& min);
	void setHour(const size_t& hour);
	void setMin(const size_t& min);
	size_t getHour() const;
	size_t getMin() const;

	void  operator=(const Time& obj);
	friend std::ostream& operator<<(std::ostream& os,const Time& obj);
	friend bool& operator==(const Time& objFirst,const Time& objSecond);
	friend bool operator<(const Time& objFirst, const Time& objSecond);

private:
	size_t hour;
	size_t min;
};

