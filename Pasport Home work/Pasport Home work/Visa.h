#pragma once
#include"Date.h"

class Visa
{
public:
	Visa(const std::string& country,const Date& date);
	void setDate(const Date& date);
	void setCountry(const std::string& country);
	friend std::ostream& operator<<(std::ostream& os, const Visa& obj);

private:
	Date date;
	std::string country;
};

