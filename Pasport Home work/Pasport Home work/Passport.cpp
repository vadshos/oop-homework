#include "Passport.h"

Passport::Passport(const std::string& fullName, const std::string& seria, const size_t& number, const Date& date, const Date& dateGive)
{
	setFullName(fullName);
	setSeria(seria);
	setNumber(number);
	setDate(date);
	setDateGive(dateGive);
}

void Passport::setFullName(const std::string& fullName)
{
	
	size_t found = fullName.find(" ");
	if (found != std::string::npos) {
		this->fullName.firstName = fullName.substr(0,found);
		size_t oldFound = found+1;
		found = fullName.find(" ", found+1);
		if (found != std::string::npos) {
			this->fullName.lastName = fullName.substr(oldFound, found-5);
			this->fullName.patronymic = fullName.substr(found, fullName.length());
		}
	}
}

void Passport::setDate(const Date& date)
{
	this->date.setDate(date.getDay(), date.getMonth(), date.getYear());
}

void Passport::setDateGive(const Date& date)
{
	this->dateGive.setDate(date.getDay(), date.getMonth(), date.getYear());
}

void Passport::setNumber(const size_t& number)
{
	std::string temp = std::to_string(number);
	if (temp.length() == 9)
	{
		this->number = number;
	}
}

void Passport::setSeria(const std::string& seria)
{
	if (seria.length() == 2) {
		this->seria = seria;
	}
}

std::ostream& operator<<(std::ostream& os, const Passport& obj)
{
	os << "First Name : " << obj.fullName.firstName << std::endl;
	os << "Last Name : " << obj.fullName.lastName << std::endl;
	os << "Patronymic : " << obj.fullName.patronymic << std::endl;
	os << std::endl;
	os << "Seria :" << obj.seria << std::endl;
	os << "Number : " << obj.number << std::endl;
	os << std::endl;
	os << "Date birth day : " <<obj.date <<std::endl;
	os << std::endl;
	os << "Date give : " << obj.dateGive << std::endl;
	return os;
}
