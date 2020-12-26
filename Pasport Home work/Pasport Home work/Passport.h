#pragma once
#include <iostream>
#include <string>

#include"Date.h"

class Passport
{
public:
	Passport(const std::string& fullName, const std::string& seria, const size_t& number, const Date& date, const Date& dateGive);
	void setFullName(const std::string& fullName);
	void setDate(const Date& date);
	void setDateGive(const Date& date);
	void setNumber(const size_t& number);
	void setSeria(const std::string& seria);
	friend std::ostream& operator<<(std::ostream& os,const Passport& obj);
private:
	struct FullName
	{
		friend class Passport;
		std::string firstName;
		std::string lastName;
		std::string patronymic;
	};
	FullName fullName;
	std::string seria;
	size_t number;
	Date date;
	Date dateGive;
};

