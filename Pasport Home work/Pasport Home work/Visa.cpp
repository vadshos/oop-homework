#include "Visa.h"

Visa::Visa(const std::string& country, const Date& date)
{
	setDate(date);
	setCountry(country);
}

void Visa::setDate(const Date& date)
{
	
		this->date.setDate(date.getDay(), date.getMonth(), date.getYear());
	
}

void Visa::setCountry(const std::string& country)
{
	if (!country.empty())
		this->country = country;
}

std::ostream& operator<<(std::ostream& os, const Visa& obj)
{
	os << "Country : " << obj.country << std::endl;
	os << "Date : " << obj.date << std::endl;
	return os;
}
